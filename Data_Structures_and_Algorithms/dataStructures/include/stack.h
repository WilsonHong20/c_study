
#ifndef LINERLIST_H
#define LINERLIST_H
#include "../include/error.h"


//---------------------顺序栈的存储结构---------------------------------//
#define MAXSIZE 100
typedef struct stack 
{
    int *base;
    int *top;
}SqStack;



void *InitStack(void *base, size_t nitem, size_t size);
void DestoryStack(void);
void ClearStack(void *);
status StackEmpty(void *);
int stackLength(void *);
void *GetTop(void *);
void push(void *,void *);
void pop (void *,void*);
void StackTraverse(void *);



#endif

