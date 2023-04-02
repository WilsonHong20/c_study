
#ifndef STACK_H
#define STACK_H
#include "../include/error.h"
#include <string.h>
#include <stddef.h>

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
status StackisEmpty_liner(SqStack *stack);
int stackLength_liner(SqStack *stack);
void GetTop_liner(SqStack *stack,void *data);
void push_liner(SqStack *stack,void *data,size_t size);
void pop_liner(SqStack *stack,void *data);
void StackTraverse_liner(SqStack *stack);

//---------------------链表栈的存储结构---------------------------------//

typedef  struct StackNode
{
   StackItem *items;
   struct StackNode *next;   
}StackNode,LinkStack;


void InitStack_link(LinkStack *stack);
void DestoryStack_link(LinkStack *stack);
status StackisEmpty_link(LinkStack *stack);
int stackLength_link(LinkStack *stack);
void GetTop_link(LinkStack *stack,void *data);
void push_link(LinkStack *stack,void *data,size_t size);
status pop_link(LinkStack *stack,void *data);



#endif

