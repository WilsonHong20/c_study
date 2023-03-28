#include"../include/test.h"

void test_alarm(){
        int seconds;
    char line[128];
    char message[64];

    while(1)
    {
        printf("Alarm> ");
        if(fgets(line,sizeof(line), stdin) == NULL) exit(0);
        if(strlen(line) <= 1) 
            continue;

        /*解析输入的行到秒（%d）和一个消息（%64[^ \n]）,由最多 64 个字符组成，以空格与秒分隔*/
        if(scanf(line, "%d %64[^\n]", &seconds, message) < 2)
        {
            fprintf(stderr,"bad command \n");
        }
        else
        {
            sleep(seconds);
            printf("(%d) %s\n", seconds,message);
        }

    }
}
void test_fget(){
    char str[20];
    printf("请输入一个字符串：");
    fgets(str,7,stdin);
    printf("%s\n",str);
}
void test_fprintf(){
    /*******************************
    int fprintf(FILE *stream, const char *format, ...)
    ***************/
    FILE *stream; 
    //stream = fopen("test.txt","w+");
    //fprintf(stream,"%s %s %d","hello","world",2023);
    stream = fopen("README.md","a+");
    fprintf(stream,"%s %s\n","#","C语言学习");
    fprintf(stream,"%s %s %s %d\n","#","hello","world",2023);
    fprintf(stream,"%s %s \n","hello","world");
    fclose(stream);
}
void test_macro(){
    printf_macro_info(buffer_duplication_error_strings,BUFFER_DUPLICATION_N_ERROR);
}
void test_memcpy()
{
    char *str = "hello world";
    bufwrite(str,10);
}
void test_mytimer()
{
    struct mytimeval tv;
    while (1)
    {
        //get system time
        gettimeofday(&tv,NULL);
        printf("s = %ld us = %ld\n",tv.tv_sec,tv.tv_usec);
        sleep(1);
    }
}
