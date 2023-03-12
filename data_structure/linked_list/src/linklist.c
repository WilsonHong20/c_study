#include "linklist.h"

/**
 * @brief 初始化生成一个{0 1 2 3 4}的链表
 * 
 * @return Linklist* 生成的链表头结点指针
 */
Linklist *initLinklist()
{
    Linklist *p = (Linklist *) malloc(sizeof(Linklist)); //定义一个头节点
    p->elem = 0;
    Linklist *tmp = p;   //定义tmp指向头节点

    for(int i = 0; i < 5; i++)
    {
        Linklist *a = (Linklist *) malloc(sizeof(Linklist));
        a->elem = i;
        a->next = NULL;
        tmp->next = a;      //将a节点挂在头节点后面
        tmp = tmp->next ;  //将tmp指针指向插入的节点
    }
    return p;
}


/**
 * @brief 删除某个节点　　
 * 
 * @param L 操作的链表
 * @param data 删除的链表数据
 */
void delete_linkNode(Linklist *L, int data)
{
    Linklist *tmp;
    Linklist *ldel;

    //如果链表只有头结点
    if(L->next == NULL)
        return;
    L = L->next;  //头节点指向第一个节点
    //首先遍历找到这个data对应的上一个node
    while(L->next != NULL)
    {
        if(L->elem != data && L->next->elem == data)
        {
            tmp = L;                  //将待删节点的上一个节点指针赋给tmp
            ldel = L->next;           //将待删节点指针赋给ldel
            goto label;
        }
        else
            L = L->next;
    }
    label:
    tmp->next = ldel ->next;
    free(ldel);
}

/*
 * @brief 增加某个节点
 * 
 * @param L 指向操作的链表的头结点
 * @param pre_node_data 需要增加节点的上一个节点的data
 * @param data 需要增加节点的data
 */
void add_linkNode(Linklist *L, int pre_node_data,int data)
{
    Linklist *tmp;
    do{
        if(L->next == NULL)
            printf("链表中没有这样的元素！！\n");
        else
            L = L->next;
    }while (L->elem != pre_node_data && L->next != NULL);
    tmp = L;
    Linklist *new_node = (Linklist *) malloc(sizeof(Linklist));
    new_node->elem = data;
    new_node->next = tmp->next;
    tmp->next = new_node;
}

struct Linklist *head_insert (struct Linklist *l)
{
    Linklist *a; //指向待插入的链表

    //创建链表
    Linklist *L = (Linklist *) malloc(sizeof(Linklist));
    a->next = L->next;
    L->next = a;
    return L;
}

//遍历某个节点
void traverse_linklist(Linklist *L)
{
    Linklist *tmp = (Linklist *)malloc(sizeof(Linklist));
    tmp = L;     //获取头结点
    while(L ->next != NULL)
    {
        L = L->next;
        printf("%d ",L->elem);
    }
    L = tmp;     //将链表指针指向头结点
    printf("\n");
}

/***************************************************************************************************************************
 ************************************************************************************************************************** 
 *************************************************************************************************************************** 
 * *************************************************************************************************************************/
/**
 * @brief  单链表的初始化
 * @note   :1.生成新节点作为头节点，用头指针L指向头节点  2.头节点的指针域置空
 * @param  *L: 单链表
 * @retval 
 */
status InitList(LinkList *L){
    L = (LNode *) malloc(sizeof(LNode)); 
    L->next = NULL;
    return OK;
}
/**
 * @brief  :单链表的取值
 * @note   ：
 * @param  L:链表 
 * @param  i: 位置索引
 * @param  data: 数据
 * @retval 
 */
int  GetElem(LinkList L,int i){
    int data = 0;
    for(int j = 0 ; j< i ; j++)
    {
        if(!L.next)
            return ERROR;
        L = *(L.next);
    }
    data = L.data;
    return data;
}
/**
 * @brief  查询元素所在位置
 * @note   
 * @param  L: 操作的链表
 * @param  data: 元素数据
 * @retval 
 */
LNode *LocateElem(LinkList L,int data)
{
    LNode *p;
    do
    {
        L = *(L.next);
        if(L.data == data)
        {
            p = &L;
            break;
        }
    } while (!L.next);
    return p;
}
/**
 * @brief  链表中插入节点
 * @note   
 * @param  *L: 所操作的链表指针
 * @param  i: 插入的位置
 * @param  data: 插入节点的数据
 * @retval 
 */
status ListInsert(LinkList *L,int i,int data)
{
    LNode *tmp;
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    if(!L->next)
    {
        L->next = node;
        node->next = NULL;
    }else
    {
        do
        {
            L = L->next;
            i--;
        } while (L->next && i > 0);

        node->next = L->next;
        L->next = node;
    }
    return OK;
}
/**
 * @brief  删除链表中的节点
 * @note   
 * @param  *L: 操纵的链表
 * @param  i: 删除的位置
 * @retval 
 */
status Listdelete(LinkList *L,int i)
{
    if(!L->next) return ERROR;
    LNode *node = (LNode *) malloc(sizeof(LNode));
    for(int j = 0; j < i -1 ; j++)
    {
        L = L->next;
    }
    node = L->next;
    L->next = L->next->next;
    free(node);
    return OK;
}
/**
 * @brief  头插法
 * @note   
 * @param  *L: 操作的链表
 * @param  n: 插入节点的数据
 * @retval None
 */
void Head_insert_list(LinkList *L,int data)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    if(!L->next)  //如果只有一个头节点
    {
        L->next = node;
        node->next = NULL;
    }else
    {   
        node->next = L->next;
        L->next = node;
    }
}
/**
 * @brief  尾插法
 * @note   
 * @param  *L: 操作的链表
 * @param  n: 插入节点的元素
 * @retval None
 */
void Tail_insert_list(LinkList *L,int data)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;
    if(!L->next)
    {
        L->next = node;
    }
    do
    {
        L = L->next;
    } while (L->next);
    L->next = node;
}

void CreateList_H(LinkList *L,int n){}
void CreateList_R(LinkList *L,int n){}
//循环链表
void Create_Circular_Linked_List(LinkList *L,int n){}
status ListInsert_DuL(DuLinkList *L,int i, int data){}
status Listdelete_DuL(DuLinkList *L,int i, int data){}

//遍历某个节点
void traverse_LinkList(LinkList *L)
{
   LNode *hNode = L;     //获取头结点
    while(L->next)
    {
        L = L->next;
        printf("%d ",L->data);
    }
    L = hNode;     //将链表指针指向头结点
    printf("\n");
}


int main(void)
{
    /********************************/
    //Linklist *L = initLinklist();
    //traverse_linklist(L);
    //delete_linkNode(L,0);
    //traverse_linklist(L);
    /********************************/

    LinkList L ;
    InitList(&L);
    ListInsert(&L,1,1);
    ListInsert(&L,2,2);
    ListInsert(&L,3,3);
    traverse_LinkList(&L);   //1 2 3 
    Head_insert_list(&L,4);
    Head_insert_list(&L,5);
    traverse_LinkList(&L);   //5 4 1 2 3 
    Tail_insert_list(&L,1);  //5 4 1 2 3 1
    traverse_LinkList(&L);

    Listdelete(&L,3);
    Listdelete(&L,5);
    traverse_LinkList(&L);    // 5 4 2 3
    
    int data = GetElem(L,2);
    printf("第二位的数据是%d\n",data);  //4

    return 0;
}
