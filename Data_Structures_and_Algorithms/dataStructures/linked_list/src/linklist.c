#include "../include/linklist.h"

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
LinkList* InitList(){
    LinkList *L = (LNode *) malloc(sizeof(LNode)); 
    L->next = NULL;
    return L;
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
    assert(L != NULL);
    LNode *tmp;
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    if(L->next == NULL)
    {
        L->next = node;
        node->next = NULL;
    }else
    {
        do
        {
            L = L->next;
            i--;
        } while ((L->next !=NULL) && i > 0);

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
    if(L->next == NULL) return ERROR;
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
    if(L->next == NULL)  //如果只有一个头节点
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
    LinkList *head = NULL;
    head = L;   //记录头节点
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;
    if(L->next == NULL)
    {
        L->next = node;
    }
    do
    {
        L = L->next;
    } while (L->next != NULL);
    L->next = node;
    L = head;
}
/**
 * @brief  前插法创建单链表
 * @note   
 * @param  *L: 创建的链表
 * @param  n: 生成链表的数据域
 * @retval None
*/
void CreateList_H(LinkList *L,int n){
    assert(L);    //L不为空
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        p->data = i;
        p->next = L->next;
        L->next = p;
    }
}
void CreateList_R(LinkList *L,int n){
    assert(L);    //L不为空
    LinkList *head = L;
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LinkList));
        p->data = i;
        p->next = NULL;
        while (L->next != NULL)
        {
            L = L->next;
        }
        L->next = p;
        L = p;
    }
    //链表指针再指回头节点
    L = head;
}

//遍历某个节点
void traverse_LinkList(LinkList *L)
{
   LNode *hNode = L;     //获取头结点
    while(L->next != NULL)
    {
        L = L->next;
        printf("%d ",L->data);
    }
    L = hNode;     //将链表指针指向头结点
    printf("\n");
}

/**
 * @brief  创建循环链表
 * @note   
 * @param  *L: 循环链表
 * @param  n: 循环链表的长度
 * @retval None
*/
void Create_Circular_Linked_List(LinkList *L,int n){
    LinkList *head = L;
    for (int i = 0; i < n; i++)
    {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        node->next = NULL;

        L->next = node;
        L = node;
    }
    L->next = head;
    L = head;
}
/**
 * @brief  遍历环形链表
 * @note   
 * @param  *L: 环形链表
 * @retval None
*/
void traverse_Circular_Linked_List(LinkList *L)
{
    assert(L != NULL);
    assert(L->next != NULL);
    assert(L->next != L); //不为空表
    LinkList *head = L;
    while (L->next != head )
    {
        L = L->next; 
        printf("%d ",L->data);
    }
    L = head;
    printf("\n");
}
/**
 * @brief  遍历打印n次循环链表
 * @note   
 * @param  *L: 操作的循环链表
 * @param  n: 打印次数
 * @retval None
*/
void traverse_Circular_Linked_List_n(LinkList *L,int n)
{
    assert(L != NULL);
    assert(L->next != NULL);
    assert(L->next != L); //不为空表
    LinkList *head = L;
    for (int i = 0; i < n; i++)
    {
        L = L->next;
        if(L == head)
            L = L->next; 
        printf("%d ",L->data);
    }
    L = head;
    printf("\n");
}


/**
 * @brief  初始化双向循环链表
 * @note   
 * @retval 双向链表指针
*/
DuLinkList* InitDulList()
{
    DuLinkList *DulList =(DuLinkList *) malloc(sizeof(DuLinkList));
    DulList->next = DulList;
    DulList->prior = DulList;
    return DulList;
}
/**
 * @brief  向循环双向链表中插入节点
 * @note   
 * @param  *L: 操作的双向循环链表
 * @param  i: 插入的位置  大于零
 * @param  data: 插入节点的数据域值
 * @retval 
*/

status ListInsert_DuL(DuLinkList *L,int i, int data){
    assert(L != NULL);
    assert(i > 0);
    DuLNode *node = (DuLNode *)malloc(sizeof(DuLNode));
    node->data = data;
    DuLNode *head = L;
    if(L->next == head)
    {
        L->next = node;
        L->prior = node;
        node->next = L;
        node->prior = L;
    }
    else{
        do
        {
            L = L->next;
            --i;
        } while ((L ->next!= head)&& (i > 0));
        
        node->next = L->next;
        node->prior = L;
        L->next->prior = node;
        L->next = node;
    }
    L = head;
    return OK;
}
/**
 * @brief  删除双向链表中的某个元素
 * @note   
 * @param  *L: 操作的双向循环链表
 * @param  i: 删除元素的位置
 * @param  data: 删除的元素
 * @retval 
*/
status Listdelete_DuL(DuLinkList *L,int i, int data){
    DuLNode *head = L;
    DuLNode *delNode = NULL;
    assert(L->next != head);
    assert(L != NULL);
    do
    {
        if(L->next->data == data)
        {
            delNode = L->next;
            L->next->next->prior = L;
            L->next = L->next->next;
            free(delNode);
        }
        i--;
        L = L->next;
    } while (i > 0 && L->next != head);
    L = head;
    return OK;
}
/**
 * @brief  遍历双向循环链表中的元素
 * @note   
 * @param  *L: 操作的双向链表
 * @retval None
*/
void traverse_DuL_Linked_List(DuLinkList *L)
{   
    assert(L != NULL);
    assert(L->next != NULL);
    DuLNode *head = L;
    do
    {
        L = L->next;
        printf("%d ",L->data);

    } while (L->next != head);
    printf("\n");
    L = head;
}
/**
 * @brief  遍历双向循环链表中的元素
 * @note   
 * @param  *L: 操作的双向链表
 * @param  n: 打印的元素个数
 * @retval None
*/
void traverse_DuL_Linked_List_n(DuLinkList *L,int n){

    assert(L != NULL);
    assert(L->next != NULL);
    assert(L->next != L); //不为空表
    DuLNode *head = L;
    for (int i = 0; i < n; i++)
    {
        L = L->next;
        if(L == head)
            L = L->next; 
        printf("%d ",L->data);
    }
    L = head;
    printf("\n");

}

/**
 * @brief  合并两个顺序链表
 * @note   已知单链表l1 l2的元素按值非递减排列
 * @param  *l1: 
 * @param  *l2: 
 * @retval None
 */
LinkList* MergeList_L(LinkList *l1,LinkList * l2){
    LinkList *l3 ;
    LNode *p1 = l1->next;
    LNode *p2 = l2->next;
    l3 = l1;
    LNode *p3 =  l3;
    while (p1 && p2)
    {
        if(p1->data <= p2->data)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next; 
        }   
        else
        {
            p3->next  = p2;
            p3 = p2;
            p2  = p2->next;
        } 
    }
    p3->next = p1 ? p1 : p2;    //p3如果指向NULL 则表示l1短些，如果还指向p1则表示l1长些
    
    free(l2);
    return l3;
}

int main(void)
{
    #if 0
    /********************************/
    //Linklist *L = initLinklist();
    //traverse_linklist(L);
    //delete_linkNode(L,0);
    //traverse_linklist(L);
    /********************************/


    LinkList *L ;
    L = InitList();
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,3);
    traverse_LinkList(L);   //1 2 3 
    Head_insert_list(L,4);
    Head_insert_list(L,5);
    traverse_LinkList(L);   //5 4 1 2 3 
    Tail_insert_list(L,1);  //5 4 1 2 3 1
    traverse_LinkList(L);

    Listdelete(L,3);
    Listdelete(L,5);
    traverse_LinkList(L);    // 5 4 2 3
    
    int data = GetElem(*L,2);
    printf("第二位的数据是%d\n",data);  //4

    LinkList *hl = NULL;
    hl = InitList();
    LinkList *rl = NULL ;
    rl = InitList();

    CreateList_H(hl,5);//4 3 2 1 0 
    traverse_LinkList(hl);

    CreateList_R(rl,5); // 0 1 2 3 4 
    traverse_LinkList(rl);
    

    LinkList *CL = NULL;
    CL = InitList();
    Create_Circular_Linked_List(CL,5); //0 1 2 3 4 -> 0 1 2 3 4 ...
    traverse_Circular_Linked_List(CL);  // 0 1 2 3 4
    traverse_Circular_Linked_List_n(CL,8); // 0 1 2 3 4 0 1 2 
    traverse_Circular_Linked_List_n(CL,16);


    /************双向链表***************/

    DuLinkList *DL;
    DL = InitDulList();
    ListInsert_DuL(DL,1,1);
    ListInsert_DuL(DL,2,2);
    ListInsert_DuL(DL,3,3);
    ListInsert_DuL(DL,3,4);
    ListInsert_DuL(DL,3,5);  //1 2 5 3 4 

    traverse_DuL_Linked_List(DL);
    Listdelete_DuL(DL,1,1);
    Listdelete_DuL(DL,2,3);
    traverse_DuL_Linked_List(DL);

    traverse_DuL_Linked_List_n(DL,16);


    /****************************/
    #endif

    LinkList *l1 ;
    l1 = InitList();
    ListInsert(l1,1,3);
    ListInsert(l1,2,5);
    ListInsert(l1,3,8);
    ListInsert(l1,4,11);  
    traverse_LinkList(l1);   //1 2 3 

    LinkList *l2 ;
    l2 = InitList();
    ListInsert(l2,1,2);
    ListInsert(l2,2,6);
    ListInsert(l2,3,8);
    ListInsert(l2,4,9);  
    ListInsert(l2,5,11);
    ListInsert(l2,6,15);
    ListInsert(l2,7,20);
    traverse_LinkList(l2);   //1 2 3 


    LinkList *l3;
    l3 = myMergeList_L(l1,l2);
    traverse_LinkList(l3);   //1 2 3 
    return 0;
}
