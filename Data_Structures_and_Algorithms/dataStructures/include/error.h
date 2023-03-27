
#ifndef ERROR_H
#define ERROR_H

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

#define MAXSIZE 100 

typedef enum
{
    ERROR = 0,
    OK = 1    ,
    OVERFLOW =2
}status;


#endif 