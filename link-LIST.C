#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;//self-referencial structure
};
struct node* getnode(int n)
{
    struct node*ptrnew=(struct node*)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);

    }
    ptrnew->data=n;
    ptrnew->next=NULL;
    return ptrnew;

}
void insertAtLast(struct node*header,struct node*ptrnew)
{
    struct node*ptrthis=header
    if(header==Null)
    header=prtNew;
else{
    while (header->next!=Null)
    ptrthis=ptrthis->next;
    ptrthis=ptrthis->ptr;
}
void main()
{
    int i;
    clrscr();
    for(i=0;i<10;i++)
    {
        insertAtLast(header,getnode(i+1));
    }

    getch();
}