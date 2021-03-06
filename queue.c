#include<stdio.h>

 /// *** CIRCULAR QUEUE ***

#define Q_SIZE 5
typedef struct {
    int head;
    int tail;
    int data[Q_SIZE+1];

    } Queue;

 void enqueue(Queue *q, int item)
{
    if((q->tail+1) % (Q_SIZE +1) == q->head)
    {
        printf("Queu is full\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail+1)%(Q_SIZE+1);
}

int dequeue(Queue *q)
{
    int item;
    if(q->tail == q->head){
        printf("Queue is empty\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head+1)%(Q_SIZE+1);

    return item;
}


int main()
{
    Queue my_q;
    int item;

    my_q.head = 0;
    my_q.tail = 0 ;

    enqueue(&my_q, 10);
    printf("tail = %d\n",my_q.tail);
    enqueue(&my_q, 20);
    printf("tail = %d\n",my_q.tail);

    printf("Beginning head = %d\n",my_q.head);
    item = dequeue(&my_q);
    printf("item = %d, head = %d\n",item,my_q.head);
    item = dequeue(&my_q);
    printf("item = %d, head = %d\n",item,my_q.head);
    item = dequeue(&my_q);
    printf("item = %d, head = %d\n",item,my_q.head);


    return 0;
}


