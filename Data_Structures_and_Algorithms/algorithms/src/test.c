
#include"../include/test.h"

void test_sha256(){
    const unsigned char h[] = "hello world!";
    unsigned char out[256] ;

    sha256(h,sizeof(out),out);
    printf("%s\n",out);
}

void test_monotonic_stack(){
    int nums[] = {5, 3, 1, 2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result[numsSize];
    next_greater(nums, numsSize, result);
    int i;
    printf("Result: ");
    for (i = 0; i < numsSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}