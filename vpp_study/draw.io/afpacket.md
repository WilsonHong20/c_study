# 结构体说明(MMAP模式下的socket)
```c
/*
   Frame structure:
   - Start. Frame must be aligned to TPACKET_ALIGNMENT=16
   - struct tpacket_hdr
   - pad to TPACKET_ALIGNMENT=16
   - struct sockaddr_ll
   - Gap, chosen so that packet data (Start+tp_net) alignes to TPACKET_ALIGNMENT=16
   - Start+tp_mac: [ Optional MAC header ]
   - Start+tp_net: Packet data, aligned to TPACKET_ALIGNMENT=16.
   - Pad to align to TPACKET_ALIGNMENT=16
 */

struct tpacket_req {
        unsigned int    tp_block_size;  /* Minimal size of contiguous block */
        unsigned int    tp_block_nr;    /* Number of blocks */
        unsigned int    tp_frame_size;  /* Size of frame */
        unsigned int    tp_frame_nr;    /* Total number of frames */
};
```
[说明]：上面的两种结构体，用于接收缓冲区的分配，
该缓冲区并不是一个传统的一块内存，而是有着固定的结构，因为这块内存会用于内核和用户程序之间的交互，两者需要配合使用。
-  tp_block_size用于指定要分配的内存块的尺寸，这里设置为4096，即1页；
-  tp_block_nr代表要分配的块的数量，即要分配多少个页，这里分配了4个页。这里的内存分配是以块大小作为单位的，每个块都是连续的物理内存，因此块大小最好要是页的整数倍。
-  frame用于设置帧的大小，可以理解为单个报文缓冲区的大小，这里设置为2048，因为单个以太网报文一般不会超过1500字节。注意：块的大小要是帧的整数倍，即帧不能大于块。
-  tp_frame_nr代表帧的数量，可以看出这是个多余的参数，因为可以根据前面的参数算出来。
-  其中 **tp_block_size*tp_block_nr = tp_frame_size * tp_frame_nr**

# 帧格式
每个帧都由两部分构成：struct tpacket和data，其中tpacket代表着帧的头部，存储着当前帧的信息，包括状态等；data存储着报文的数据。目前内核中有三个版本的原始套接字，每个版本在帧格式以及数据交互上都有一些出入.
1. 首先我们来看一下V1版本帧头的定义：
```c
struct tpacket_hdr {
    unsigned long          tp_status;
    unsigned long          tp_len;
    unsigned long          tp_snaplen;
    unsigned long          tp_mac;
    unsigned long          tp_net;
    unsigned long          tp_sec;
    unsigned long          tp_nsec;
    unsigned long          tp_vlan_tci;
    unsigned long          tp_vlan_tpid;
    unsigned long          tp_padding[4];
};
```

首先说一下帧的状态，对于发送和接收缓冲区，其状态是不一样的，这里以接收缓冲区为例讲解一下其常见的几种状态。

**TP_STATUS_KERNEL：**帧的状态，代表着当前帧是空闲的，里面没有数据，内核可以将报文数据放到里面；
**TP_STATUS_USER：**当前帧里面是有报文数据的，用户可以将其取走，记得取走之后将状态重置为TP_STATUS_KERNEL，好让内核继续往里放数据；
**TP_STATUS_COPY：**代表由于报文比帧要大，当前报文数据被截断了；
**TP_STATUS_CSUM_VALID：**这个报文的校验码已经检查通过了；

2. V1->V2：相对来说，V1与V2之间版本差异不算大，主要差异表现在：

- 支持64位内核使用32位用户态程序。
- 由于在V1版本中的一些结构体中使用了unsigned long，导致如果内核是64位，而用户态程序是32位，那么会产生数据交互异常；
- V2版本的帧的头部存储了VLAN信息；
**V2版本的帧头如下：**
```c
struct tpacket2_hdr {
	__u32		tp_status;
	__u32		tp_len;
	__u32		tp_snaplen;
	__u16		tp_mac;
	__u16		tp_net;
	__u32		tp_sec;
	__u32		tp_nsec;
	__u16		tp_vlan_tci;
	__u16		tp_vlan_tpid;
	__u8		tp_padding[4];
};
```
3. V2->V3：V2与V3之间的差异还是有点大的，主要表现在：

    -  使用“柔性帧”，即每个块中不再指定帧的大小，而是根据报文的大小动态的设置帧大小。这种机制直接使得块布局发生了变化，增加了一个块“头”，里面存储了当前块的信息，包括帧的数量、第一个帧的偏移量等。
    -  帧结构中也引入了一个tp_next_offset成员，用于定位当前块中下一个帧的位置。通过这种方式，块的空间利用率得到了一定的提升。
    -  鉴于上面的机制，V3版本的读操作都是以块作为单位来进行的。
V3版本的块头如下：
```c
struct block_desc {
    uint32_t version;
    uint32_t offset_to_priv;
    struct tpacket_hdr_v1 h1;
};

struct tpacket_hdr_v1 {
	__u32	block_status;	//当前块的状态，与帧状态类似
	__u32	num_pkts;		//帧的数量
	__u32	offset_to_first_pkt;	//第一个帧的位置

	__u32	blk_len;	//块中有效数据长度

	__aligned_u64	seq_num;
	struct tpacket_bd_ts	ts_first_pkt, ts_last_pkt;
};
```
V3版本的帧头格式如下：
```c
struct tpacket3_hdr {
	__u32		tp_next_offset;	//下一个帧的位置
	__u32		tp_sec;
	__u32		tp_nsec;
	__u32		tp_snaplen;
	__u32		tp_len;
	__u32		tp_status;
	__u16		tp_mac;
	__u16		tp_net;
	/* pkt_hdr variants */
	union {
		struct tpacket_hdr_variant1 hv1;
	};
	__u8		tp_padding[8];
};
```
# vpp中创建的的af-packet接口
为了解决arm，低版本的centos上ZFP2206版本vpp不支持af-packet接口的创建问题。我们在vpp中支持了v2和v3版本的数据帧

## 在v2版本的帧格式中
//todo 数据结构

## 在v3版本的帧格式中
//todo 数据结构