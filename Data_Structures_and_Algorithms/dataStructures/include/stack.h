
#ifndef STACK_H
#define STACK_H
#include "../include/error.h"
#include <string.h>
//---------------------chatgpt实现的顺序栈的存储结构---------------------------------//
 typedef struct
 {
    void *data;  //存放数据的指针
    size_t size; //数据的大小
 }StackItem;
 

 typedef struct
 {
    StackItem *items;     //存放StackItem的数组
    size_t size;         //栈的大小
    size_t top;         //栈顶的索引
 }Stack;
 
void stack_init(Stack *stack, size_t size);
void stack_destory(Stack *stack);
void stack_push(Stack *stack,void *data,size_t size);
void stack_pop(Stack *stack,void *data);

//---------------------链表栈的存储结构---------------------------------//



char DestoryStack(void);
void ClearStack(void *);
status StackEmpty(void *);
int stackLength(void *);

void StackTraverse(void *);




//-------------------------------------------------------//
void InitStack();
char DestoryStack(void);
void ClearStack(void *);
status StackEmpty(void *);
int stackLength(void *);
void *GetTop(void *);
void push(void *,void *);
void pop (void *,void*);
void StackTraverse(void *);



#endif

