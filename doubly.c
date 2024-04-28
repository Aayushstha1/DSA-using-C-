#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
    struct node*prev;

};
struct node* getnode(int n)
{
    struct node*ptrnew;
    ptrnew= (struct node*)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory allocation failed");
        getch();
        exit(0);
    }
    ptrnew->info=n;
    ptrnew->next=NULL;
    ptrnew->prev=NULL;
    return ptrnew;
}
void insertAtfront()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    ptrnew=getnode(n);
    if(header==NULL)
    {
        header=ptrnew;
        ptrnew->next=ptrnew;
        ptrnew->prev=ptrnew;

    }
    else
    {
        ptrnew->next=header->next;
        ptrnew->prev=header;
        (header->next)->prev=ptrnew;
        header->next=ptrnew;

    }
    printf("  ")
}
void main()
{
    char choice;
    do{
        clrscr();
        printf("select an option :\n1. Insert at front\n2.Insert at end");
        printf("\n3. Insert after\n4.Insert Before\n5.remove from front");
        printf("\n6. Remove from end \n7.remove any\n8.Display \n9. Exit");
        fflush(stdin);
        choice=getche();

     switch(choice)

{
    case '1':
    break;
    case '2':
    break;
    case '3':
    break;
    case '4':
    break;
    case '5':
    break;
    case '6':
    break;
    case '7':
    break;
    case '8':
    break;
    case '9':
    printf("\nIt is time to go away. Good Bye!");
    getch();
    return;
}
}
}





