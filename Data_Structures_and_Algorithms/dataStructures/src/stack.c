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
        return stack->top - stack->base;
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

//---------------------链表栈的存储结构---------------------------------//
/**
 * @brief  构造一个空栈S,栈顶指针置空
 * @note   
 * @param  *stack: 
 * @retval None
*/
void InitStack_link(LinkStack *stack){
    stack = (StackNode *)malloc(sizeof(StackNode));
    stack->items = NULL;
    stack->next = NULL;     //
}

void push_link(LinkStack *stack,void *data,size_t size){
    StackItem *item = malloc(sizeof(StackItem));
    item->data = malloc(size);
    item->size = size;
    memcpy(item->data,data,size);

    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->items = item;
    node->next = stack; 
    stack = node;
}


LinkStack *tmp_push_link(LinkStack *stack,void *data,size_t size){
    StackItem *item = malloc(sizeof(StackItem));
    item->data = malloc(size);
    item->size = size;
    memcpy(item->data,data,size);

    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->items = item;
    node->next = stack; 
    stack = node;

    return stack;
}


status pop_link(LinkStack *stack,void *data){
    assert(stack !=NULL );
    memcpy(data,stack->items->data,stack->items->size);
    StackNode *tmp;
    tmp = stack;
    stack = stack->next;
    free(tmp);
}


 LinkStack *tmp_pop_link(LinkStack *stack,void *data){
    assert(stack !=NULL );
    memcpy(data,stack->items->data,stack->items->size);
    StackNode *tmp;
    tmp = stack;
    stack = stack->next;
    free(tmp);
    return stack;
}

void GetTop_link(LinkStack *stack,void *data){
    assert(stack);
    memcpy(data,stack->items->data,stack->items->size);
}

void DestoryStack_link(LinkStack *stack){
    assert(stack);
    if(stack != NULL)
    {
        free(stack);
        stack = stack->next;
    }
    return;
}

status StackisEmpty_link(LinkStack *stack){
    if(stack == NULL)
        return OK;
    else
        return ERROR;
}


int stackLength_link(LinkStack *stack){
    int len = 0;
    if(stack == NULL)
        return len;
    do
    {
        len++;
        stack = stack->next;
    } while (stack != NULL);
    return len;
}
/**
 * @brief  遍历链表栈
 * @note   表中的数据类型必须一致
 * @param  *stack: 
 * @retval None
*/
