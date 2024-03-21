#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;//self-referencial structure
};
struct node* header;
struct node* getnode(int );
void insertAtEnd(int);
void RemoveFromFront(int);
void main()
{
    char choice;
    int n;
    header=NUll;
    do {
        clrscr();
        printf("enter your choice:\n");
        printf("1. Insert \n2. Remove \3. Display \4.EXIT");
        fflush(stdin);
        choice=getch();
    }
        switch(choice)
        {
            case '1':
            printf("Enter a number:");
            scanf("%d",&n);
            insertAtEnd(n);
            break;
              case '2':
              removeFromFront
                break;
                case '3': break;
                case '4': return;
        }
        getche(){
            struct node* ptrnew;

    ptrnew=(struct node*)malloc(sizeof(struct node));
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
void insertAtLast(int n)
{


    struct node*ptrthis, *ptrthis;
    ptrnew=getnode(n);
    if(header==Null)
    {
    header=prtNew;
    printf("%d inserted at front.",n);
    }
else{
    ptrthis=header;
    while(ptrthis->next!=NULL)
    ptrthis->next=ptrnew;
    printf("%d inserted at End.",n);
}
}
void removeFromFront(){
    struct node*ptrthis;
    if(header==NULL)
    printf("List is Empty");
else
{
    ptrthis=header;
    header=header->next;
}
}
void display();
{
    struct node*ptrthis;
    if(header==NULL)
    printf("list is empty");
else{
    ptrthis=header;
    while(ptrthiss!=NULL)
    {
        printf("%d\t, ptrthis ->data"):
        ptrthis=ptrthis->next;
    }
}
}
}