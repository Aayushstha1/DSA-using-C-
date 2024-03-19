#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define Max 10
#define true 1
#define false 0
struct Q
{
  int front;
  int rear;
  int items[MAX];  /* data */
};
int isEmpty (struct Q *q)

{
    if (q->rear<q->front)
    returnn TRUE;
    else
    return FALSE;
    /* data */
};
int isFull(struct Q* q)
{
    if(q->rear==Max-1)
    return 
}
