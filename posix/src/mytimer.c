#include<time.h>
#include<bits/types.h>
#include<stdio.h>
#include<unistd.h>

struct timeval
{
    __time_t tv_sec; /*Seconds. */
    __suseconds_t tv_usec; /*Mircoseconds. */
};

int main(void)
{   
    struct timeval tv;
    while (1)
    {
        //get system time
        gettimeofday(&tv,NULL);
        printf("s = %ld us = %ld\n",tv.tv_sec,tv.tv_usec);
        sleep(1);
    }
    return 0;
}