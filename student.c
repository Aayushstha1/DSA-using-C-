#include <stdio.h>
#include <conio.h>
#define MAX_STUDENT 100
#define MAX_NAME_LENGTH 50
#define TRUE 1
#define FALSE 0

// structure
typedef struct student
{
    char name[MAX_NAME_LENGTH];
    int id;
} Student;
typedef struct list
{
    Student students[MAX_STUDENT];
    int count;
} List;

// int isFull(struct list *lst);      // check weather list is full
// int isEmpty(struct list *lst); // chech if list is empty

// // insert functions
int insertFront(List *lst, Student std); // insert from top
// int insertEnd(struct list *lst, struct student, int);  // insert from end
// int afterItem(struct list *lst, struct student, int);  // insert after items
// int beforeItem(struct list *lst, struct student, int); // insert before items

// // remove functions
// int removeFront(struct list *);    // remove form top
// int removeLast(struct list *);     // remove from last
// int removeAny(struct list *, int); // remove any

// display list
void displayList(List *lst);

// // check list is full or not
int isFull(List *lst)
{
    if (lst->count == MAX_STUDENT - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
// // check list if empty  or not
int isEmpty(List *lst)
{
    if (lst->count = -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int insertFront(List *lst, Student std)
{
    if (isFull(lst))
    {
        printf("Student List is Full...");
    }

    int i;
    for (i = lst->count; i > 0; i--)
    {
        lst->students[i] = lst->students[i - 1];
    }
    lst->students[0] = std;

    return 0;
}

void displayList(List *lst)
{
    if (isEmpty(lst))
    {
        printf("\n....Student List is Empty...\n");
    }

    printf("Students:\n");
    for (int i = 0; i < lst->count; i++)
    {
        printf("%d. %s\n", lst->students[i].name);
    }
}

void main()
{
    char StdName[MAX_NAME_LENGTH];
    int id;
    int choice;
    List studentList;
    Student newStudent;
    studentList.count = 0;

    while (1)
    {
        printf("Student List  Program\n");
        printf("1: Insert Front\n2: Insert End\n3: Insert After Items\n4: Insert Before Items\n5: Remove Front\n6: Remove Last\n7: Remove Any\n8: Display List\n9: Search Lists");
        printf("\n--Enter Your Choice:  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Student Name: ");
            scanf("%s", StdName);
            insertFront(&studentList, newStudent);
            printf("\n.....Student List Insert Front Sucessfully......\n\n");
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
            displayList(&studentList);
            break;
        case 9:
            break;
        default:
            printf("\n!!!!!!!!!!!!!!!--Invalid Input! Please Enter Again.--!!!!!!!!!!!!!!!!!!!!!\n\n");
            break;
        }
    }
    getch();
}