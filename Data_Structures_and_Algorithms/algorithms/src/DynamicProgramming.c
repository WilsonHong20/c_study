#include"../include/DynamicProgramming.h"

int fib(int n)
{
    if (n == 2 || n == 1)   
        return 3;
    int prev = 1,curr = 1;
    for (int i = 3; i <= n; i++)
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}