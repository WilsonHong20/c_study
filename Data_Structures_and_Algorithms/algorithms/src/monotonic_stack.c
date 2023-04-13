/**
 * @brief  
 * * 该代码使用单调栈实现了解决该问题的函数 next_greater，
 * * 函数中遍历原数组 nums，并将结果数组 result 初始化为-1。然后，对于每个元素，
 * * 如果栈不为空且当前元素大于栈顶元素，就将栈顶元素出栈，
 * * 并将结果数组中对应位置设为当前元素下标减去栈顶元素下标，
 * * 即当前元素至少需要往右走多少步才能遇到一个比自己大的元素。最后，将当前元素入栈。
*/

#include"../include/monotonic_stack.h"

int stack[MAX_SIZE]; // 定义栈
int top = -1; // 栈顶指针，初始值为-1

// 判断栈是否为空
int is_empty() {
    return top == -1;
}

// 判断栈是否已满
int is_full() {
    return top == MAX_SIZE - 1;
}

// 入栈
void push(int x) {
    if (is_full()) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

// 出栈
void pop() {
    if (is_empty()) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    top--;
}

// 获取栈顶元素
int peek() {
    if (is_empty()) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return stack[top];
}

// 获取栈中元素个数
int size() {
    return top + 1;
}

// 打印栈中元素
void print_stack() {
    int i;
    printf("Stack: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// 解决问题的函数
void next_greater(int* nums, int numsSize, int* result) {
    int i;
    for (i = 0; i < numsSize; i++) {
        result[i] = -1; // 先把结果数组全部初始化为-1
    }
    for (i = 0; i < numsSize; i++) {
        while (!is_empty() && nums[i] > nums[peek()]) {
            result[peek()] = i - peek();
            pop();
        }
        push(i);
    }
}

