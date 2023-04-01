#include"../include/stack.h"

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
    if(stack->top = stack->size){
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
