#include "errors.h"
int main(void)
{
    char str[20];
    printf("请输入一个字符串：");
    fgets(str,7,stdin);
    printf("%s\n",str);
    return 0;
}