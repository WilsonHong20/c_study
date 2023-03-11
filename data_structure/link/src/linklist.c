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
        L = L->next;
        if(L->next == NULL)
            printf("链表中没有这样的元素！！\n");
    }while (L->elem != pre_node_data);
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



int main(void)
{
    Linklist *L = initLinklist();
    traverse_linklist(L);
    delete_linkNode(L,4);
    traverse_linklist(L);
    delete_linkNode(L,1);
    traverse_linklist(L);
    add_linkNode(L,3,5);
    traverse_linklist(L);
    return 0;
}
