#ifndef QUEUE_H
#define QUEUE_H
#include "../include/error.h"
#include <string.h>
#include <stddef.h>

 typedef struct
 {
    void *data;  //存放数据的指针
    size_t size; //数据的大小
 }QElemType;

/************************循环顺序队列*********************************/
typedef struct
{
    QElemType *item;   //存储空间的基地址
    int front;         //头指针
    int rear;           //尾指针
}SqQueue;

void InitQueue(SqQueue *q);
void Enqueue(SqQueue *q,void *data,size_t size);
void Dequeue(SqQueue *q,void *data);
void GetHead(SqQueue *q,void *data);
int QueueLength(SqQueue q);
status QueneEmpty(SqQueue q);
void ClearQueue(SqQueue *q);
void DestoryQueue(SqQueue *q);
void QueuieTraverse(SqQueue *q);

/************************循环链表队列*********************************/
typedef struct QNode
{
    QElemType items;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

status InitQueue_link(LinkQueue *q);
void Enqueue_link(LinkQueue *q,void *data,size_t size);
void Dequeue_link(LinkQueue *q,void *data);
void GetHead_link(LinkQueue *q,void *data);



#endif