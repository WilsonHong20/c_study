#include<stdio.h>
#include<stdlib.h>


#define foreach_buffer_duplication_error \
    _(SWAPPED,           "mac swap packets processed")\
    _(REPL_FAIL,         "multicast replication  failures")\
    _(NO_MEMBERS,        "multicast replication complete")\
    _(CLONE_ERROR,        "clone failed")\


typedef enum
{
    #define _(sym,str) BUFFER_DUPLICATION_ERRPR_##sym,
        foreach_buffer_duplication_error
    #undef _
        BUFFER_DUPLICATION_N_ERROR,
}duplication_error_t;


#ifndef TEST
static char* buffer_duplication_error_strings[] = 
{
    #define _(sym,string) string,
        foreach_buffer_duplication_error
    #undef _
};
#endif


#define printf_macro_info(p,n)  \
for(int i = 0;i < n; i++)\
{\
    printf("%s\n",p[i]);\
}\

int main(void)
{
    printf_macro_info(buffer_duplication_error_strings,BUFFER_DUPLICATION_N_ERROR);
    return 0;
}






