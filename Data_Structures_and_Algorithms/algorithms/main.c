#include"sha256.h"

int main(void)
{
    const unsigned char h[] = "hello world!";
    unsigned char out[256] ;

    sha256(h,sizeof(out),out);
    printf("%s\n",out);
    return 0;
}