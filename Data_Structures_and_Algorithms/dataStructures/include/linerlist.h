/*
 * @Author: WilsonHong20 51684532+WilsonHong20@users.noreply.github.com
 * @Date: 2023-03-26 09:56:16
 * @LastEditors: WilsonHong20 51684532+WilsonHong20@users.noreply.github.com
 * @LastEditTime: 2023-03-26 11:52:55
 * @FilePath: /c_study/Data_Structures_and_Algorithms/dataStructures/include/linerlist.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef LINERLIST_H
#define LINERLIST_H

#include<string.h>
#include "../include/error.h"
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
LinerList * MergeList_Sq(LinerList *LA,LinerList *LB, LinerList *LC);
LinerList* myMergeList_Sq(LinerList *LA,LinerList *LB);

#endif
