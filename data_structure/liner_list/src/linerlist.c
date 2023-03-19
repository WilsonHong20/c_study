#include "linerlist.h"


/**
 * @brief  构造一个空的顺序表
 * @note   
 * @param  *l: 顺序表
 * @retval 
 */
status initlist(sqllist *l)
{
    l->elem =(book *)malloc(sizeof(MAXSIZE));
    if(!l->elem) exit(OVERFLOW);
    l->length = 0;
    return OK;

}
/**
 * @brief  顺序表的取值
 * @note   
 * @param  l: 顺序表
 * @param  i: 取值索引
 * @param  *b: 值
 * @retval 
 */
status getBook(sqllist l,unsigned int i, book *b)
{
    if(i<1 || i >l.length) return ERROR;
    *b = l.elem[i -1];
    return OK;
}
/**
 * @brief  顺序表的查找
 * @note   
 * @param  l: 顺序表
 * @param  b: 查找的元素
 * @retval 
 */
int locateBook(sqllist l,book b)
{
    for(unsigned int i = 0; i < l.length; i++)
    {
        if(strcmp(l.elem[i].name,b.name) == 0)
             return i+1;
    }
    return 0;
}
/**
 * @brief  
 * @note   
 * @param  *l: 顺序表
 * @param  i: 插入的位置 i>0
 * @param  b: 插入的元素
 * @retval 
 */
status listInsert(sqllist *l,unsigned int i,book b){
    if((i<1)||(i>l->length+1)) return ERROR;
    if(l->length == MAXSIZE) return ERROR;
    if(l->length == 0)
    {
        l->elem[i-1] = b;
        ++l->length;
        return OK;
    }else
    {
        for(int j = l->length - 1; j >= i-1;j--)
        {
            l->elem[j+1] = l->elem[j];
        }
    }
    l->elem[i-1] = b;
    ++l->length;
    return OK;
}
/**
 * @brief  
 * @note   
 * @param  *l: 顺序表
 * @param  i: 删除的索引
 * @retval 
 */
status listDelete(sqllist *l,unsigned int i){
    if(i > l->length) return ERROR;
    for (unsigned int j = i; j < l->length; j++)
    {
        l->elem[j-1] = l->elem[j];
    }
    --l->length;
    return OK;
}
/**
 * @brief  遍历顺序表
 * @note   
 * @param  *l: 顺序表
 * @retval 
 */
void traverse_linerlist(sqllist *l){
    for (unsigned int i = 0; i < l->length ; i++)
    {
        printf("===========================\n");
        printf("book name  is: %s\n",l->elem[i].name);
        printf("book no    is: %s\n",l->elem[i].no);
        printf("book price is: %f\n",l->elem[i].price);
        printf("===========================\n");
    }  
}

void info_book(book b)
{
    printf("===========================\n");
    printf("book name  is: %s\n",b.name);
    printf("book no    is: %s\n",b.no);
    printf("book price is: %f\n",b.price);
    printf("===========================\n");
}

/*******************************************泛型实现如下函数*****************************************************/

/*******************************************有序表*****************************************************/
LinerList* InitList(){
    LinerList *L = malloc(sizeof(LinerList));
    if(L->elem == NULL) exit(OVERFLOW);
    L->length = 0;
    return L;
}

status LinerListInsert(LinerList *l,unsigned int i,int data){
    assert( i> 0);
    l->elem[i-1] = data;
    ++l->length ;
    return OK;
}

void traverse_LinerList(LinerList *l){
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ",l->elem[i]);
    }
    printf("\n");
}
/**
 * @brief  有序线性表的合并
 * @note   
 * @param  *LA: 有序线性表A
 * @param  *LB: 有序线性表B
 * @param  *LC: 合并后的线性表C
 * @retval None
*/

/*
void MergeList_Sq(LinerList *LA,LinerList *LB,LinerList *LC){
    LC->length = LA->length + LB->length;
    int *pa = LA->elem;
    int *pb = LB->elem;
    int *pc = LC->elem;

    int n = LA->length > LB->length ? LB->length: LA->length;
    while (n > 0 )
    {
        if(*pa++ > *pb++) 
        {
            *pc++ = *pb;
        }
        else
        {
            *pc++ = *pa;
        }
        n--;
    }
    for (int i = n; i < LC->length; i++)
    {
        *pc++ = LA->length > LB->length ? (*(pa+n)++) : (*(pb+n)++);
    }
}

*/





int main(void)
{
    #if 0
    book b1 = {"1a","三国演义",100};
    book b2 = {"2b","水浒传",200};
    book b3 = {"3c","西游记",300};
    book tmp;
    sqllist l;
    initlist(&l);
    listInsert(&l,1,b1);
    listInsert(&l,2,b2);
    listInsert(&l,2,b3);   
    traverse_linerlist(&l);

    int locate = locateBook(l,b3);
    printf("b3 locate:%d\n",locate);

    getBook(l,2,&tmp);
    info_book(tmp);

    listDelete(&l,2);
    traverse_linerlist(&l);
    #endif
    
    LinerList *A;
    A = InitList();
    LinerListInsert(A,1,3);
    LinerListInsert(A,2,5);
    LinerListInsert(A,3,8);
    LinerListInsert(A,4,11);
    traverse_LinerList(A);
    return 0;
}