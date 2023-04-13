#ifndef _MONOTONIC_STACK_H
#define _MONOTONIC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// 判断栈是否为空
int is_empty();
// 判断栈是否已满
int is_full();
// 入栈
void push(int x);
// 出栈
void pop();
// 获取栈顶元素
int peek();
// 获取栈中元素个数
int size() ; 
// 打印栈中元素
void print_stack();
// 解决问题的函数
void next_greater(int* nums, int numsSize, int* result);

#endif