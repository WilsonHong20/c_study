#ifndef LINERLIST_H
#define LINERLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

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

typedef struct LinerList 
{
    int length;
    int elem[0];
}LinerList;



status initlist(sqllist *l);
status getBook(sqllist l,unsigned int i, book *b);
int locateBook(sqllist l,book b);
status listInsert(sqllist *l,unsigned int i,book b);
status listDelete(sqllist *l,unsigned int i);
void traverse_linerlist(sqllist *l);
void info_book(book b);





//泛型实现如下函数
//LinerList* InitList(int size);
//status ListInsert(LinerList *l,unsigned int i,int data);
//status ListDelete(LinerList *l,unsigned int i);
//void traverse_linerlist(LinerList *l);



/*****************有序表的合并*********************/
LinerList* InitList();
status LinerListInsert(LinerList *l,unsigned int i,int data);
void traverse_LinerList(LinerList *l);
LinerList * MergeList_Sq(LinerList *LA,LinerList *LB,LinerList *LC);

#endif
