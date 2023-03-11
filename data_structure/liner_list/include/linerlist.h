#ifndef LINERLIST_H
#define LINERLIST_H

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10000
/**
 * @brief  图书结构体
 * @note   no:图书ISBN name:名称      price：价格
 * @retval None
 */
typedef struct Book
{
    char no[20];            
    char name[50];          
    float price;
}book;

typedef enum
{
    ERROR = 0,
    OK = 1    ,
    OVERFLOW =2
}status;

/**
 * @brief  
 * @note   
 * @retval None
 */
typedef struct sqllist 
{
    book *elem;
    int length;
}sqllist;

status initlist(sqllist *l);
status getBook(sqllist l,unsigned int i, book *b);
int locateBook(sqllist l,book b);
status listInsert(sqllist *l,unsigned int i,book b);
status listDelete(sqllist *l,unsigned int i);
void traverse_linerlist(sqllist *l);
void info_book(book b);
#endif
