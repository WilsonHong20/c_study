#include"../include/queue.h"

void InitQueue(SqQueue *q){
    q->item = malloc(MAXSIZE * sizeof(QElemType));
    if(q->item == NULL)
        return exit(OVERFLOW);
    q->front = q->rear = 0;
}

status Enqueue(SqQueue *q,void *data,size_t size){
    if((q->rear + 1) % MAXSIZE == q->front)   //尾指针在循环的意义上加1后等于头指针，表明队满
        return ERROR;
    QElemType *item = malloc(sizeof(QElemType));
    item->data = malloc(size);
    item->size = size;
    memcpy(item->data,data,size);
    q->item[q->rear] = *item;                  //新元素插入队尾
    q->rear = (q->rear + 1) % MAXSIZE;         //队尾指针增1
    return OK;
}


status Dequeue(SqQueue *q,void *data){
    if(q->front == q->rear)                                           //队空
        return ERROR;
    memcpy(data,&q->item[q->front].data,&q->item[q->front].size);    //保存对头元素
    q->front = (q->front + 1) % MAXSIZE;                             //对头指针加1
    free(&q->item[q->front]);                                        //释放对头元素指针               
    return OK;
}

void GetHead(SqQueue *q,void *data){
    if(q->front == q->rear)                                           //队空
        return ERROR;
    memcpy(data,&q->item[q->front].data,&q->item[q->front].size);    //保存对头元素
}

int QueueLength(SqQueue q){
    int len = 0;
    if(q.front == q.rear)
        return len;
    return (q.rear - q.front  + MAXSIZE) % MAXSIZE;
}

status QueneEmpty(SqQueue q){
    if(q.front == q.rear)
        return OK;
    return ERROR;
}

void ClearQueue(SqQueue *q){

}

void DestoryQueue(SqQueue *q){

}

/**
 * @brief  遍历环形队列
 * @note   环形队列元素只能是整数
 * @param  *q: 
 * @retval None
*/
void QueuieTraverse(SqQueue *q){
    if(q->front == q->rear){
        printf("队列为空！！");
        return;
    }
    for(int i = 0; i < q->rear - q->front; i++)
    {
        printf("%d ",q->item[q->front + i]);
    }
    printf("\n");
}




status InitQueue_link(LinkQueue *q){
    q->front = q->rear = malloc(sizeof(QNode));
    q->front->next = NULL;
    return OK;
}

void Enqueue_link(LinkQueue *q,void *data,size_t size){
    QElemType *item = malloc(sizeof(QElemType));
    item->data = malloc(size);
    item->size = size;
    memcpy(item->data,data,size);

    QNode *node = malloc(sizeof(QNode));      //为入队元素分配节点空间，用指针node指向
    node->items = *item;                       //将新节点数据域置为QElemType                 
    node->next = NULL;                  
    q->rear->next = node;                     //将新节点插入到队尾
    q->rear = node;                           //修改队尾指针              
}

void Dequeue_link(LinkQueue *q,void *data){
    if(q->front == q->rear)
    {
        printf("该链表队列为空！！\n");
        return;
    }
    QNode *node = malloc(sizeof(QNode));

    node = q->front->next;
    memcpy(data,node->items.data,node->items.size);
    q->front->next = node->next;
    if(q->rear == node)
        q->rear = q->front;
    free(node);    
}

void GetHead_link(LinkQueue *q,void *data){
    if(q->front == q->rear){
        printf("该队列为空队列！！\n");
        return;
    }
    memcpy(data,q->front->next->items.data,q->front->next->items.size);
}
