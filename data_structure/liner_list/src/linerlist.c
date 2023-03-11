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

int main(void)
{
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

    return 0;
}