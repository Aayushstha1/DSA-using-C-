#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
    struct node*prev;
};
 struct node*header;
struct node* getnew(int n)
{
    struct node*ptrnew;
    ptrnew=(struct node*)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->info=n;
    ptrnew->next=NULL;
    ptrnew->prev=NULL;
    return ptrnew;
}
void insertAtFront()
{
    int n;
    struct node*ptrnew;
    printf("Enter a number.");
    scanf("%d",&n);
    ptrnew=getnode(n);
    if(header==NULL)//if new node is the only node in the list
    {
        header=ptrnew;
        ptrnew->next=ptrnew;
        ptrnew->prev=ptrnew;
    }
    else// if list already contains one or many items
    {
        ptrnew->next=header->next;
        ptrnew->prev=header;
        (ptrnew->next)->prev=ptrnew;
        header->next=ptrnew;
    }
    printf("yItem is inserted at front");
 }
 void insertAtEnd()
 {
    int n;
    struct node*ptrnew;
    printf("Enter a number.");
    scanf("%d",&n);
    if(header==NULL)//if new node is the only node in the list.
    
        {
         header = ptrnew;
         ptrnew->next = header;
         ptrnew->prev = header;
       }
     else //if list already contains one or many items
       {
         ptrnew->next = header;
         ptrnew->prev = header->prev;
         header->prev->next = ptrnew;
         header->prev = ptrnew;
       }
     printf("Item inserted at the end.\n");
 }
 void insertAfter()
 {
    int key,n;
    struct node*ptrthis;
    if(header==NULL)
    printf("\n list is empty.");
else 
{
   printf(" Enter a number after which you want to insert new number ");
    scanf("%d", &key);
    ptrthis=header->next;
    do 
    {
        if(ptrthis->info==key)
        {
            printf("\nEnter new number you want to insert:");
            scanf("%d", &n);
            ptrnew=getnode(n);
            ptrnew->prev=ptrthis ->prev;
            ptrnew->next=ptrthis;
            (ptrnew->next)->prev=ptrnew;
            ptrthis->next=ptrnew;
            return;
        }
        ptrthis=ptrthis->next;
         }
    while(ptrthis!=header->next);
    printf("\n There is no node with key value %d",key);
 }
 void display()
 {
    struct node*ptrthis;
    if(header==NULL)
     printf("\nList is Empty.");
     else{
         printf("\nList contains.\n");
         ptrthis=header->next;// print to the first mode
         do{
            printf("%d\t",ptrthis->info);
            ptrthis=ptrthis->next;
         }while(ptrthis!=header->next);
        }
 }
 void main()
 {
    char choice;
    header=NULL; //initially list is empty
    do{
        printf("Select an option \n1. Insert at Front\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Remove from front\n6. Remove from end\n7. Remove any\n8. Display\n9. Exit");
        fflush(stdin);   //This is needed to clear any pendding keystrokes
        choice=getch();
        switch(choice)
        {
         case 1:
         insertAtFront();
         break;
         case 2:
         break;
         case 3:
         break;
         case 4:
         break;
         case 5:
         break;
         case 6:
         break;
         case 7:
            break;
         case 8:
            break;
         case 9:
         printf("\n It is time to go away. Good bye!");
         getch();
         return;
        }
     }while();
    
 }
 }