
#ifndef STACK_H
#define STACK_H
#include "../include/error.h"
#include <string.h>

 typedef struct
 {
    void *data;  //存放数据的指针
    size_t size; //数据的大小
 }StackItem;
 
//---------------------chatgpt实现的顺序栈的存储结构---------------------------------//
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

//---------------------实现的顺序栈的存储结构---------------------------------//
typedef struct 
{
   StackItem *base;             //栈底指针
   StackItem *top;              //栈顶指针
   size_t size;            //栈的大小
}SqStack;

void InitStack_liner(SqStack *stack, size_t size);
void DestoryStack_liner(SqStack *stack);
void ClearStack_liner(SqStack *stack);
status StackEmpty_liner(SqStack *stack);
int stackLength_liner(SqStack *stack);
void GetTop_liner(SqStack *stack,void *data);
void push_liner(SqStack *stack,void *data,size_t size);
void pop_liner(SqStack *stack,void *data);
void StackTraverse_liner(SqStack *stack);

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

