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

/****************************************************************/
Linklist *initLinklist();
void delete_linkNode(Linklist *L, int data);
void add_linkNode(Linklist *L, int pre_node_data,int data);
struct Linklist *head_insert (struct Linklist *l);
void traverse_linklist(Linklist *L);

/****************************************************************/

typedef enum
{
    ERROR = 0,
    OK = 1    ,
    OVERFLOW =2
}status;

typedef struct LNode
{
    int data;
    struct LNode *next;    
}LNode,LinkList;


status InitList(LinkList *L);
int GetElem(LinkList L,int i);
LNode *LocateElem(LinkList L,int data);
status ListInsert(LinkList *L,int i,int data);
status Listdelete(LinkList *L,int i);

//构造头插法链表
void CreateList_H(LinkList *L,int n);

//构造尾插法链表
void CreateList_R(LinkList *L,int n);

void Head_insert_list(LinkList *L,int data);

void Tail_insert_list(LinkList *L,int data);


//循环链表
void Create_Circular_Linked_List(LinkList *L,int n);

//双向链表
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;    //直接前驱
    struct DuLNode *next;     //直接后继
}DuLNode,*DuLinkList;

status ListInsert_DuL(DuLinkList *L,int i, int data);
status Listdelete_DuL(DuLinkList *L,int i, int data);

void traverse_LinkList(LinkList *L);
#endif
