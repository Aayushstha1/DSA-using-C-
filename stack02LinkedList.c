#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *header;
struct node *getNode(int data) {
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("\nMemory Allocation failed.");
        getch();
        exit(0);
    }

    ptrnew->info = data;
    ptrnew->prev = ptrnew->next = NULL;
    return ptrnew;
}

void insertAtEnd() {
    int data;
    struct node *newNode, *ptrThis;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (header == NULL) { //empty list
        header = newNode;
        printf("inserted at the front.");
    } else {
        ptrThis = header;
        while (ptrThis->next != NULL) {
            ptrThis = ptrThis->next;
        }
        ptrThis->next = newNode;
        newNode->prev = ptrThis;
    }
    return;
}

void insertAfter() {
    struct node *newNode, *ptrThis;
    int data, key;
    if (header == NULL)
        printf("List is empty.");
    else {
        printf("Enter a key number after which you want to insert new node.: ");
        scanf("%d", &key);
        for (ptrThis = header; ptrThis != NULL; ptrThis = ptrThis->next) {
            if (ptrThis->info == key) { //if the node is found
                printf("Enter a number to be inserted: ");
                scanf("%d", &data);
                newNode = getNode(data);
                newNode->next = ptrThis->next;
                newNode->prev = ptrThis;
                if (ptrThis->next != NULL) //if we are adding in the middle
                    (ptrThis->next)->prev = newNode;
                ptrThis->next = newNode;
                printf("Inserted after %d", ptrThis->info);
                return;
            }
        }
        printf("Node not found with the key value %d", key);
    }
}

void insertBeforeKey() {
    struct node *newNode, *ptrThis;
    int data, key;
    if (header == NULL)
        printf("List is empty.");
    else {
        printf("Enter a key number before which you want to insert new node.: ");
        scanf("%d", &key);
        for (ptrThis = header; ptrThis != NULL; ptrThis = ptrThis->next) {
            if (ptrThis->info == key) { //if the node is found
                printf("Enter a number to be inserted: ");
                scanf("%d", &data);

                newNode = getNode(data);
                newNode->next = ptrThis;
                newNode->prev = ptrThis->prev;
                
                if (ptrThis->prev != NULL)      //if we are adding in the middle or at the start
                    (ptrThis->prev)->next = newNode;
                else    //if we are adding at the start
                    header = newNode;
                ptrThis->prev = newNode;
                printf("Inserted before %d", ptrThis->info);
                return;
            }
        }
        printf("Node not found with the key value %d", key);
    }
}

void removeFromFront() {
    if (header == NULL)
        printf("List is empty.");
    else {
        int data = header->info;
        struct node *temp = header;
        if (header->next == NULL) { //if single item in the list
            free(header);
            header = NULL;
        } else {
            header = header->next;
            header->prev = NULL;
            free(temp);
        }
        printf("%d was removed from the front.", data);
    }
}

void removeFromEnd()
{
    struct node* ptrThis;
    if(header=NULL)
    {
        printf("List is empty.\n");
    }

    else        //if list contains one or more items
    {
        if(header->next==NULL)      //if there is only one item in the list 
        {
            free(header);
            header=NULL;
        }

        else    //if list contains more than one items
        {
            ptrThis=header;
            while (ptrThis->next!=NULL)         //while we reach the last node
                ptrThis=ptrThis->next;      //go forward one node
            (ptrThis->prev)->next=NULL;
            free(ptrThis);
        }
        printf("Item removed from end.\n");
    }

}

void removeAny()
{
    int key;
    struct node *ptrThis;
    if(header==NULL)
    {
        printf("List is Empty.\n");
    }

    else
    {
        printf("Enter a number you want to remove.\n");
        scanf("%d", &key);
        for(ptrThis=header; ptrThis!=NULL; ptrThis->next)
        {
            if(ptrThis->info==key)          //if node found
            {
                if(ptrThis==header)         //if it is the first item
                {
                    header=header->next; 
                    if(header!=NULL)
                        header->prev=NULL;  

                }
                
                else if(ptrThis->next==NULL)         //if it is the last item
                    {
                        if(ptrThis->prev!=NULL)
                            (ptrThis->prev)->next=NULL;
                    }

                else
                {
                    (ptrThis->prev)->next=ptrThis->next;
                    (ptrThis->next)->prev=ptrThis->prev;
                }

                free(ptrThis);
                printf("Item removed from list.");
                return;
            }
        }
    }
}

void display() {
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.\n");
    else {
        printf("\nList contains: \n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
            printf("%d\t", ptrthis->info);
    }
}

void main() {
    char choice;
    header = NULL; //initialize empty list;

    do {
        printf("\nSelect Your Choice: ");
        printf("\n1.InsertAtEnd \n2.Remove From Front \n3.Display \n4.Exit \n5.Insert Before \n6.Remove From End\n7.Insert After\n");

        fflush(stdin);
        choice = getche();
        switch (choice) {
        case '1':
            insertAtEnd();
            break;

        case '2':
            removeFromFront();
            break;

        case '3':
            display();
            break;

        case '4':
            return;

        case '5':
            insertBeforeKey();
            break;

        case '6':
            removeFromEnd();
            break;

        case '7':
            insertAfter();
            break;

        default:
            ("Wrong Selection. Try Again.\n");
        }
    } while (1);
    getch();
}
