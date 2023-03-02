#include<stdio.h>
#include<stdlib.h>

/*******************************
int fprintf(FILE *stream, const char *format, ...)

***************/


int main(void)
{
    FILE *stream; 
    //stream = fopen("test.txt","w+");
    //fprintf(stream,"%s %s %d","hello","world",2023);
    stream = fopen("README.md","a+");
    fprintf(stream,"%s %s\n","#","C语言学习");
    fprintf(stream,"%s %s %s %d\n","#","hello","world",2023);
    fprintf(stream,"%s %s \n","hello","world");
    fclose(stream);
    return 0;
}