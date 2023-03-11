#定义变量
#ARCH默认为x86,使用gcc编译器，否则使用arm编译器

ARCH ?= x86
TARGET = linklist

#存放中间文件的路径：./build_arm
BUILD_DIR := build_$(ARCH)
#存放源文件的文件夹：./src
SRC_DIR := src
#存放头文件的文件夹:./include
IDIR := include
#源文件.c
#在src目录下有main.c linklist.c
#执行如下函数 $(wildcard src/*.c)函数的输出为：
#src/linklist.c src/main.c
SRC := $(wildcard $(SRC_DIR)/*.c)

#notdir函数用于去除文件路径中的目录部分 例如输入参数”./src/main.c”，函数执行后 
#"main.c" 也就是说它会把输入中的”./src/”路径部分去掉，保留文件名
#OBJS变量用于存储所有要生成的的.o文件，它的值为patsubst函数 的输出，本例子中该函数是把所有c文件名
#替换为同名的.o文件，并添加build目录，即函数的输 出为”build/main.o build /linklist.o ”。
#目标文件（*.o）
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC)))

#DEPS变量存储所有依赖的头文件，它的值为wildcard函数的输出，本例子中该函数的输出为”include/linklist.h “。
#头文件
DEPS := $(wildcard $(IDIR))/*.h)

#指定头文件的路径
#用于存储包含的头文件路径，它的值为patsubst函数的输出，
#本例子中该函数是把includes目录添加到”-I”后面，函数的输出为”-Iincludes”。
CFLAGS := $(patsubst %, -I%, $(IDIR))

#根据输入的ARCH变量来选择编译器
#ARCH=x86，使用gcc
#ARCH=arm，使用arm-gcc


ifeq ($(ARCH),x86)
CC := gcc
else
CC := arm-linux-gnueabihf-gcc
endif

#目标文件
#build_arm/linklist: build/main.o build/linklist.o 
$(BUILD_DIR)/$(TARGET): $(OBJS)
# gcc -o build_arm/linklist   build/linklist.o  -Iinclude
	$(CC) -o $@ $^ $(CFLAGS)  
#-Idir 
#在你是用 #include "file" 的时候, gcc/g++ 会先在当前目录查找你所制定的头文件,
#如果没有找到, 他回到默认的头文件目录找, 如果使用 -I 制定了目录,他会先在你所制定的目录查找, 
#然后再按常规的顺序去找。
#对于 #include<file>, gcc/g++ 会到 -I 制定的目录查找, 查找不到, 然后将到系统的默认的头文件目录查找 。

#*.o文件的生成规则
#例：build/main.o : src/main.c include/linklist.h
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)  
#创建一个编译目录，用于存放过程文件
#命令前带"@",表示不在终端上输出
	@mkdir -p $(BUILD_DIR)
#gcc -g -c -o build/main.o src/main.c -Iincludes
	$(CC) -c -o $@ $ $(CFLAGS) 


#伪目标
.PHONY: clean cleanall a
#按架构删除
clean:
	rm -rf $(BUILD_DIR)

#全部删除
cleanall:
	rm -rf build_x86 build_arm
