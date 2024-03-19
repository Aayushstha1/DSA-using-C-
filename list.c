#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for list node
typedef struct Node {
    int id;             // Example field: ID
    char name[50];      // Example field: Name
    struct Node *next;  // Pointer to next node
} Node;

// Function prototypes
void insertAtEnd(Node **head, int id, const char *name);
void insertAtFront(Node **head, int id, const char *name);
void insertAfter(Node *prevNode, int id, const char *name);
void insertBefore(Node **head, Node *nextNode, int id, const char *name);
void removeFromFront(Node **head);
void removeFromEnd(Node **head);
void removeItem(Node **head, int id);
void listItems(Node *head);
Node *searchItem(Node *head, int id);
void exitProgram(Node *head);

int main() {
    Node *head = NULL;  // Initialize the list as empty

    int choice;
    int id;
    char name[50];

    do {
        // Display menu
        printf("  1. Insert At end\n");
        printf("  2. Insert At front\n");
        printf("  3. Insert After an item\n");
        printf("  4. Insert Before an item\n");
        printf("  5.Remove From front\n");
        printf("  6.Remove From end\n");
        printf("  7.Remove Any item\n");
        printf("  8.List items\n");
        printf("  9.Search an item by ID\n");
        printf("  10.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertAtEnd(&head, id, name);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertAtFront(&head, id, name);
                break;
            case 3:
                printf("Enter ID of the previous item: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertAfter(searchItem(head, id), id, name);
                break;
            case 4:
                printf("Enter ID of the next item: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertBefore(&head, searchItem(head, id), id, name);
                break;
            case 5:
                removeFromFront(&head);
                break;
            case 6:
                removeFromEnd(&head);
                break;
            case 7:
                printf("Enter ID to remove: ");
                scanf("%d", &id);
                removeItem(&head, id);
                break;
            case 8:
                listItems(head);
                break;
            case 9:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Node *result = searchItem(head, id);
                if (result != NULL) {
                    printf("Item found: ID = %d, Name = %s\n", result->id, result->name);
                } else {
                    printf("Item not found.\n");
                }
                break;
            case 10:
                exitProgram(head);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while(choice != 10);

    return 0;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int id, const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the front of the list
void insertAtFront(Node **head, int id, const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = *head;

    *head = newNode;
}

// Function to insert a node after a specific node
void insertAfter(Node *prevNode, int id, const char *name) {
    if (prevNode == NULL) {
        printf("Previous node is NULL. Cannot insert.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node before a specific node
void insertBefore(Node **head, Node *nextNode, int id, const char *name) {
    if (nextNode == NULL) {
        printf("Next node is NULL. Cannot insert before.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = nextNode;

    if (*head == nextNode) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != nextNode) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node from the front of the list
void removeFromFront(Node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to remove a node from the end of the list
void removeFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    free(curr);
    prev->next = NULL;
}

// Function to remove a specific node based on ID
void removeItem(Node **head, int id) {
    if (*head == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;

    // Traverse the list to find the node with the given ID
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    // If the node is found, remove it
    if (curr != NULL) {
        if (prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    } else {
        printf("Item with ID %d not found.\n", id);
    }
}

// Function to display all items in the list
void listItems(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List of items:\n");
    while (head != NULL) {
        printf("ID: %d, Name: %s\n", head->id, head->name);
        head = head->next;
    }
}

// Function to search for an item by ID
Node *searchItem(Node *head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to exit the program and free memory
void exitProgram(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    printf("Exiting program. Memory freed.\n");
    exit(0);
}