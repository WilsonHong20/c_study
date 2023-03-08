#include<stdio.h>
#include<stdlib.h>

#ifndef LINKLIST_H
#define LINKLIST_H

/**
 * @brief 链表数据结构
 * 
 */
typedef struct Linklist  
{
    int elem;
    struct Linklist *next;
}Linklist;


Linklist *initLinklist();
void delete_linkNode(Linklist *L, int data);
void add_linkNode(Linklist *L, int pre_node_data,int data);
struct Linklist *head_insert (struct Linklist *l);
void traverse_linklist(Linklist *L);


#endif
