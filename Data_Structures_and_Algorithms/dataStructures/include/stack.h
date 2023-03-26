
#ifndef STACK_H
#define STACK_H
#include "../include/error.h"


//---------------------顺序栈的存储结构---------------------------------//
#define MAXSIZE 100

#define new(type,n) (type *)malloc(n * sizeof(type))
#define delete(var) free(var)

/**
 * @brief  定义数据类型为T的SqStack_##T栈的结构体
 * @note   
 * @retval 
*/
#define tStack(T) \
typedef struct stack_##T \ 
{\
    T *base; \
    T *top; \
    int stacksize; \
}SqStack_##T   \

/**
 * @brief  初始化SqStack_##T栈
 * @note   
 * @param  *this: 指向该栈的指针
 * @retval None
*/
#define tInitStack(T)   \
SqStack_##T *InitStack(){\
    SqStack_##T *this = new(SqStack_##T,MAXSIZE);\
    if(this->base == NULL || this->top == NULL) exit(OVERFLOW);\
    this->base = this->top;\
    this->stacksize = MAXSIZE;\
    return this;\
}\
/**
 * @brief  创建一个栈
 * @note   
 * @param  *e: 指向元素的首地址
 * @retval 
*/
#define tCreateStack(T) \
SqStack_##T *CreateStack(T *e){\
    SqStack_##T *this = new(SqStack_##T,MAXSIZE);\
    if(this->base == NULL || this->top == NULL) exit(OVERFLOW);\
    *this->top ++ = *e++;\
    return this;\
}\

/**
 * @brief  入栈函数
 * @note   
 * @param  *this: 指向该栈的指针
 * @param   e :入栈的元素 
 * @retval 
*/
//#define tPush(T)\  
//status push(SqStack_##T *this ,T e){\
//    if(this->top - this->base == this->stacksize) \
//        return ERROR;\
//    *this->top ++ = e;\
//    return OK;\
//}\

/**
 * @brief  出栈函数
 * @note   
 * @param  *this: 指向该栈的指针
 * @param  e: 出栈的元素 
 * @retval None
*/
#define tPop(T)\
status pop (SqStack_##T *this ,T e){\
    if(this->top == this->base)\
        return ERROR;\
    e = * --this->top;\
    return  OK;\
}\

/**
 * @brief  
 * @note   
 * @param  *this: 指向该栈的指针
 * @retval 返回栈顶元素
*/
#define tGetTop(T)\
T GetTop(SqStack_##T  *this){\
    if(this->top != this->base)\
        return *(this->top - 1)\
}\

/*
 * @brief  遍历栈
 * @note   
 * @param  *this:  指向该栈的指针
 * @retval None
 */
/*
#define info(a) printf("%d",*a->top--)
#define tStackTraverse(T)\
void StackTraverse(SqStack_##T *this ){\
    if(this->top != this->base)\    //不为空栈
       info(this);\
}\
*/



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

