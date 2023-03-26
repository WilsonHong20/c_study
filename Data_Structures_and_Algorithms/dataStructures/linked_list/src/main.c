#include "../include/linklist.h"
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

    #endif

    Polynomial *pl1;
    struct parameter para1[4] = {{7,0},{3,1},{9,8},{5,17}};
    int len1 = sizeof(para1) / sizeof(struct  parameter);
    pl1 = InitPolynomial();
    createPolynomial(pl1,len1,para1);
    foreach_poly(pl1);


    Polynomial *pl2;
    struct parameter para2[3] = {{8,1},{22,7},{-9,8}};
    int len2 = sizeof(para2) / sizeof(struct  parameter);
    pl2 = InitPolynomial();
    createPolynomial(pl2,len2,para2);
    foreach_poly(pl2);

    Polynomial *pl;
    pl = AddPolyn(pl1,pl2);
    foreach_poly(pl);
    return 0;
}