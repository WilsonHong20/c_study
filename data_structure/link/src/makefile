#下面的makefile定义了include文件夹，lib文件夹路径，并且把目标文件放到src文件夹的子文件夹obj里面。
#同时，还定义了一个宏，用于包含任何你想要包含的库，比如math库-lm。这个makefile文件应该位于src目录，注意，
#这个makefile 还包含了一个规则用于清理source和obj文件夹，只需要输入make clean即可。
#.PHONY规则可以让make不去改动任何名为clean的文件（如果有的话）。

IDIR = ../include
CC = gcc
CFLAGS =-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

###1.patsubst函数用于将文件模式进行替换。
###2.替换文件后缀。
###3.$(patsubst 原模式， 目标模式， 文件列表)
_DEPS=linklist.h
DEPS=$(pathsubst %,$(IDIR)/%,$(_DEPS)) 

_OBJ = linklist.o
OBJ = $(pathsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o:%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

linklist:$(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:clean
clean:
	rm -rf $(ODIR)/*.o $(OBJ)





