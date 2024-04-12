#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *header; //declare external pointer header that points to the list

struct node *getNode(int data)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("\nMemory allocation failed.");
        exit(0);
    }
    ptrnew->info = data;
    ptrnew->prev = ptrnew->next = NULL;
    return ptrnew;
}

void insertAtEnd()
{
    int data;
    struct node *newNode, *ptrthis;
    printf("Enter a number:");
    scanf("%d", &data);
    newNode = getNode(data);
    if (header == NULL) //empty list
    {
        header = newNode;
        printf("Inserted at the front.");
    }
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
            ; //move to last node
        ptrthis->next = newNode;
        newNode->prev = ptrthis;
        printf("Inserted at the end.");
    }
}

void insertAtFront()
{
    int data;
    struct node *newNode;
    printf("Enter a number:");
    scanf("%d", &data);
    newNode = getNode(data);
    if (header == NULL) //empty list
        header = newNode;
    else
    {
        newNode->next = header;
        header->prev = newNode;
        header = newNode;
    }
    printf("Inserted at the front.");
}

void insertAfter()
{
    struct node *newNode, *ptrthis;
    int data, key;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a key number after which you want to insert new node:");
        scanf("%d", &key);
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            if (ptrthis->info == key) //if node found
            {
                printf("Enter a number:");
                scanf("%d", &data);
                newNode = getNode(data);
                newNode->next = ptrthis->next;
                newNode->prev = ptrthis;
                if (ptrthis->next != NULL) //if we are adding in the middle
                    (ptrthis->next)->prev = newNode;
                ptrthis->next = newNode;
                printf("Inserted after %d", ptrthis->info);
                return;
            }
        }
        printf("Node not found with key value %d", key);
    }
}

void removeFromFront()
{
    int data;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        data = header->info;
        if (header->next == NULL) //if single item in the list
        {
            free(header);
            header = NULL;
        }
        else
        {
            header = header->next;
            free(header->prev);
            header->prev = NULL;
        }
        printf("%d was removed from the front.", data);
    }
}

void removeFromEnd()
{
    struct node *ptrthis;
    if (header == NULL) //list is empty
    {
        printf("List is empty.");
    }
    else //if list contains one or more items
    {
        if (header->next == NULL) //if there is only one item in the list
        {
            free(header);
            header = NULL;
        }
        else //if list contains more than one items
        {
            ptrthis = header;
            while (ptrthis->next != NULL) //until we reach the last node
                ptrthis = ptrthis->next;   //go forward one node
            (ptrthis->prev)->next = NULL;
            free(ptrthis);
        }
        printf("Item removed from end.");
    }
}

void removeAny()
{
    int key;
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a number you want to remove:");
        scanf("%d", &key);
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            if (ptrthis->info == key) //if node found
            {
                if (ptrthis == header) //if it is first item
                {
                    header = header->next;
                    if (header != NULL)
                        header->prev = NULL;
                }
                else if (ptrthis->next == NULL) //if it is last item
                    (ptrthis->prev)->next = NULL;
                else
                {
                    (ptrthis->prev)->next = ptrthis->next;
                    (ptrthis->next)->prev = ptrthis->prev;
                }
                free(ptrthis);
                printf("Item removed from list.");
                return;
            }
        }
        printf("Item does not exist in the list.");
    }
}

void display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("\nList contains:\n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
            printf("%d\t", ptrthis->info);
    }
}

int main()
{
    char choice;
    header = NULL; //initialize empty list;
    do
    {
        printf("Select your choice:");
        printf("\n1. Insert at front \n2. Insert at end\n3. Insert after \n4. Remove From Front\n5. Remove From End\n6. Remove Any\n7. Display\n8. Exit");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtEnd();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            removeFromFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            removeAny();
            break;
        case '7':
            display();
            break;
        case '8':
            return 0;
        default:
            printf("Wrong selection. Try again!");
        }
    } while (1);
}
