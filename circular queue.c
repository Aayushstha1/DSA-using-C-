#define max 50 
struct cqueue
{
 int front ;
 int rear;
 int items[maxsize];
};
typedef struct cqueue cq;
// the isempty function 
int isempty()
{
    if(rear==front)
    return 1;
    else 
    return 0;

}
// the isfull function
int isfull()
{
    if(front==(rear+1)%size)
    return 1;
    else
    return 0;
    //the enqueue function
    void enqueue(cq*q, int newitem)
    {
        if(q->front==(q->rear+1)%maxsize)
        {
            printf("queue is full");
            exit(1);
            
        }
        else
        {
            q->rear=(q->rear+1)%maxsize;
            q->items[q->rear]=newitem;
        }
    }
    //the dequeue function \addindex
    int dequeue(cq *q)
    {
        if (q->rear<q->front)
        {
        printf("queue is empty");
        exit(1);
    }
    else
    {
        q->front=(q->front+1)%maxsize;
        return(q->items[q->front]);
    }

    
}
