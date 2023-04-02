#include"../include/stack.h"

//---------------------chatgpt实现的顺序栈的存储结构---------------------------------//
//初始化栈
void stack_init(Stack *stack, size_t size)
{
    stack->items = malloc(sizeof(StackItem) * size);
    stack->size = size;
    stack->top = 0;
}

//销毁栈
void stack_destory(Stack *stack){
    free(stack->items);
    stack->items = NULL;
    stack->size = 0;
    stack->top = 0;
}

//压栈
void stack_push(Stack *stack,void *data,size_t size){
    if(stack->top == stack->size){
        printf("Stack is full.\n");
        return;
    }
    StackItem *item = &stack->items[stack->top++];
    item->data = malloc(size);
    memcpy(item->data,data,size);
    item->size = size;
}

//弹栈
void stack_pop(Stack *stack,void *data){
    if(stack->top == 0){
        printf("Stack is empty.\n");
        return;
    }
    StackItem *item = &stack->items[--stack->top];
    memcpy(data,item->data,item->size);
    free(item->data);
    item->data - NULL;
    item->size = 0;
}


//---------------------链表栈的存储结构---------------------------------//

void InitStack_liner(SqStack *stack, size_t size){

    stack->base = malloc(sizeof(StackItem) *size);
    assert(stack->base);
    stack->top = stack->base;
    stack->size = size;
}
void DestoryStack_liner(SqStack *stack){
    free(stack->base);
    stack->base = stack->top = NULL;
    stack->size = 0;
}
void ClearStack_liner(SqStack *stack){
    if(stack->base == stack->top)
        return;
    
}
status StackisEmpty_liner(SqStack *stack){
    if(stack->base == stack->top)
        return OK;
    else
        return ERROR;
}
int stackLength_liner(SqStack *stack){
    if(stack->base == stack->top)
        return ERROR;
    else   
        return (stack->top - stack->base)/sizeof(StackItem);
}
void GetTop_liner(SqStack *stack,void *data)
{
    if(stack->base == stack->top)
        printf("Stack is en");
    else
    { 
        StackItem *tmp = stack->top;
        StackItem *item = (--tmp);
        memcpy(data,item->data,item->size);
    }
}
void push_liner(SqStack *stack,void *data,size_t size){
    if(stack->top == stack->base + stack->size)
    {
        printf("sqstack is full.\n");
        return;
    }
    StackItem *item = stack->top++;
    item->data = malloc(size);
    memcpy(item->data,data,size);
    item->size = size;
}
void pop_liner(SqStack *stack,void *data){
    if(stack->base == stack->top)
        printf("sqstack is empty.\n");
    StackItem *item = --stack->top;
    memcpy(data,item->data,item->size);  
    free(item->data);
    item->data = NULL;
    item->size = 0;
}


void StackTraverse_liner(SqStack *stack)
{

}