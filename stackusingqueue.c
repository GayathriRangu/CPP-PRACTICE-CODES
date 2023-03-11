#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *arr;
    int rear,front,count,max;
};
struct queue *allocate(int n);
void queue_insert(struct queue *q, int v);
int queue_remove(struct queue *q);
int queue_count(struct queue *q);
int qisempty(struct queue *q);

void stack_push(struct queue *q, int v)
{
    queue_insert(q,v);
}
int stack_pop(struct queue *q)
{
    int i,n=queue_count(q);
    int rem;
    for(i=0;i<n-1;i++)
    {
        rem=queue_remove(q);
        queue_insert(q,rem);
    }
    rem=queue_remove(q);
    return rem;
}

int stackisempty(struct queue *q)
{
return qisempty(q);
}
int stack_count(struct queue *q)
{
    return queue_count(q);
}
 int queue_count(struct queue *q)
 {
    return q->count;
 }
 struct queue *allocate(int n)
 {
    struct queue *q;
    q=malloc(sizeof(struct queue));
    if(q==NULL)
    return NULL;
    q->max=n;
    q->arr=malloc(sizeof(int)*n);
    q->rear=-1;
    q->front=-1;
    return q;

 }
 void queue_insert(struct queue *q,int v)
 {
    if(q->count==q->max)
    return;
    if(q->count==0)
    q->front++;
    q->rear=(q->rear+1)%q->max;
    q->arr[q->rear]=v;
    q->count++;
 }

 int queue_remove(struct queue *q)
 {
    int rem;
    if(q->count==0)
    return 0;
    rem=q->arr[q->front];
    q->front=(q->front+1)%q->max;
    q->count--;
    return rem;
    
 }
 int qisempty(struct queue *q)
 {
    return (q->count==0);
 }
 void queue_display(struct queue *q)
 {
    int i=q->front;
    elements=queue_count(q);
    while(elements--)
    {
        printf("[%d]",q->arr[i]);
        i=(i>=q->max)?0:(i+1);

    }
 }

 int main()
 {
    struct queue *q;
    int x,choice;
    q=allocate(5);
    do{
        printf("[1] PUSH [2] POP [3] EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     
            printf("enter values to insert\n");
            scanf("%d",&x);
             stack_push(q,x);
             printf("\n\n");
             queue_display(q);
             break;
            case 2:
            x=stack_pop(q);

            printf("%d\n\n",x);
            break;
            case 3:
            printf("quitting\n");
            return 0;


        }

    }while(1);
    return 0;

 }