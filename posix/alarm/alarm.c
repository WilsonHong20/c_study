#include "errors.h"
#include<string.h>
int main( int argc, char *argv[])
{
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