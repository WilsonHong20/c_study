
#include "../include/memcpy.h"

void my_memcpy(char *dst, char *src,int n)
{
    while(n-- > 0) 
    {
        if(src != &dst[n])
        {
            *dst ++ = *src++ ;
        }else
        {
            printf("越界了！！！！！\n");
        }
    }    
}

void bufwrite(char *p,int n)
{
    char buffer[MAXSIZE] = {0};
    char *bufptr = buffer;
    while (n > 0)
    {
        int k,rem;
        if(bufptr == &buffer[MAXSIZE]) //当缓冲区写满时
        {
            printf("%s\n",buffer);
            memset(buffer,0,sizeof(buffer));
            exit(1);
        }
        rem = MAXSIZE - (bufptr - buffer);
        k = n >rem ? rem:n;
        my_memcpy(bufptr,p,k);
        bufptr += k;
        n -= k;
        p +=k;
    }  
    printf("%s\n",buffer);
}
