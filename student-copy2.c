
Nishan
Nishan Pradhan
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *header = NULL;

struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew = malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory Allocation Failed..");
        getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}

void main()
{
    char choice;
    header = NULL;
    do
    {
        printf("\n ________Enter your choice_______\n");
        printf("|\t1. Insert At Front\t|\n|\t2. Insert from after\t|\n|\t3. Insert at last\t|\n|\t4. Remove From Front\t|\n|\t5. Remove From Last\t|\n|\t6. Remove From Any\t|\n|\t7. Display\t\t|\n|\t8. Exit\t\t\t|");
        printf("\n---------------------------------\n");
        printf("--> ");
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':
            // insertAtFront();
            break;
        case '2':
            // insertAfter();
            break;
        case '3':
            insertAtEnd();
            break;
        case '4':
            // removeAtFront();
            break;
        case '5':
            // removeAtEnd();
            break;
        case '6':
            // removeAtAny();
            break;
        case '7':
            // display();
            break;
        case '8':
            printf("Program Exit Successfully...");
            exit(0);
            break;

        default:
            break;
        }
    } while (1);
}

void insertAtFront()
{
    int n;
    struct node *ptrnew;
    printf("Enter a number");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew;
        ptrnew->prev = ptrnew;
    }
}

void insertAtEnd()
{
    struct node *ptrnew;
    int n;
    printf("Enter a numner: ");
    scanf("%d", &n);
    if (header == NULL)
    {
        // printf("List is Empty..");
        header = ptrnew;
        ptrnew->next = ptrnew;
        ptrnew->prev = ptrnew;
    }
    else
    {
        ptrnew->next = ptrnew;
        ptrnew->prev = header;
        (header->next)->prev = ptrnew;
        header->next = ptrnew;
        header = ptrnew;
    }
    printf("\n%d Inserted at the font.", n);
}