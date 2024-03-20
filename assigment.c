#include <stdio.h>
#include <stdlib.h>

// Define a structure for the list node
typedef struct ListNode {
    int data; // Assuming integer data for simplicity
    struct ListNode* next;
} ListNode;

// Function to create a new node
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the front of the list
void insertAtFront(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new node after a given item
void insertAfter(ListNode* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    ListNode* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a new node before a given item
void insertBefore(ListNode** head, ListNode* nextNode, int data) {
    if (*head == NULL || nextNode == NULL) {
        printf("Previous node or head cannot be NULL.\n");
        return;
    }
    if (*head == nextNode) {
        insertAtFront(head, data);
        return;
    }
    ListNode* current = *head;
    while (current->next != nextNode && current->next != NULL) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Given next node not found in the list.\n");
        return;
    }
    ListNode* newNode = createNode(data);
    newNode->next = nextNode;
    current->next = newNode;
}

// Function to remove the first node from the list
void removeFromFront(ListNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    ListNode* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to remove the last node from the list
void removeFromEnd(ListNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    ListNode* temp = *head;
    ListNode* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to remove a specific node from the list
void removeNode(ListNode** head, ListNode* target) {
    if (*head == NULL || target == NULL) {
        printf("List or target node cannot be NULL.\n");
        return;
    }
    if (*head == target) {
        removeFromFront(head);
        return;
    }
    ListNode* temp = *head;
    ListNode* prev = NULL;
    while (temp != target && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Given target node not found in the list.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print all items in the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for an item by a given field
ListNode* searchItem(ListNode* head, int key) {
    ListNode* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

int main() {
    ListNode* head = NULL;

    int choice, data, key;
    do {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. List Items\n");
        printf("4. Search by Field\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n1. At the Front\n");
                printf("2. At the End\n");
                printf("3. After an Item\n");
                printf("4. Before an Item\n");
                printf("Enter insert choice: ");
                int insertChoice;
                scanf("%d", &insertChoice);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                switch (insertChoice) {
                    case 1:
                        insertAtFront(&head, data);
                        break;
                    case 2:
                        insertAtEnd(&head, data);
                        break;
                    case 3:
                        printf("Enter data of the item after which to insert: ");
                        scanf("%d", &key);
                        ListNode* afterNode = searchItem(head, key);
                        if (afterNode != NULL) {
                            insertAfter(afterNode, data);
                        } else {
                            printf("Item not found.\n");
                        }
                        break;
                    case 4:
                        printf("Enter data of the item before which to insert: ");
                        scanf("%d", &key);
                        ListNode* beforeNode = searchItem(head, key);
                        if (beforeNode != NULL) {
                            insertBefore(&head, beforeNode, data);
                        } else {
                            printf("Item not found.\n");
                        }
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 2:
                printf("\n1. From Front\n");
                printf("2. From End\n");
                printf("3. Remove Any Item\n");
                printf("Enter remove choice: ");
                int removeChoice;
                scanf("%d", &removeChoice);
                switch (removeChoice) {
                    case 1:
                        removeFromFront(&head);
                        break;
                    case 2:
                        removeFromEnd(&head);
                        break;
                    case 3:
                        printf("Enter data of the item to remove: ");
                        scanf("%d", &data);
                        ListNode* nodeToRemove = searchItem(head, data);
                        if (nodeToRemove != NULL) {
                            removeNode(&head, nodeToRemove);
                        } else {
                            printf("Item not found.\n");
                        }
                        break;
                    default:
                        printf("Invalid choice!\n);