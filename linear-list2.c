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
        for (ptrThis = header; ptrThis->next != NULL; ptrThis = ptrThis->next); //move to last node
        ptrThis->next = newNode;
        newNode->prev = ptrThis;
        printf("inserted at the end.");
    }
}

void removeFromFront() {
    int data;
    if (header == NULL)
        printf("List is empty.");
    else {
        data = header->info;
        if (header->next == NULL) { //if single item in the list
            free(header);
            header = NULL;
        } else {
            struct node *temp = header;
            header = header->next;
            header->prev = NULL;
            free(temp);
        }
        printf("%d was removed from the front.", data);
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

int main() {
    char choice;
    header = NULL; //initialize empty list;

    do {
        printf("Select Your Choice: ");
        printf("\n1.Insert \n2.Remove \n3.Display \n4.Exit\n");
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
            return 0;

        default:
            printf("Wrong Selection. Try Again.\n");
        }
        getch();
    } while (1);
    getch();
}
