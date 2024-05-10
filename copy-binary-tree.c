#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *father;
    struct node *left;
    struct node *right;
};

struct node *root;
struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew=(struct node *)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory Allocation Failed.\n");
        getch();
        exit(0);
    }
    ptrnew->info=n;
    ptrnew->father=NULL;
    ptrnew->left=NULL;
    return ptrnew;
}

void bstInsert()
{
    int n;
    struct node *ptrnew, *current=root, *parent=NULL;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    ptrnew=getnode(n);
    while(1)
    {
        if(current==NULL)       //it is time to insert new node
        {
            if(root==NULL)      //if it is the first node in the bst. then make it root
            {
                root=ptrnew;
                printf("%d inserted as the root node.",n);
            }

            else        //new node will be inserted as either left or right son of parent
            {
                if(n<parent->info)      //insert as the left son
                {
                    parent->left=ptrnew;
                    printf("%d inserted as the left son of %d", n, parent->info);
                }

                else
                {
                    parent->right=ptrnew;
                    printf("%d inserted as the right son of %d", n, parent->info);
                }

                ptrnew->father=parent;
            }
            return;
        }

        else if(n<current->info)        //if new value is less than current node value then go to left subtree
        {
            parent=current;
            current=current->left;
        } 

        else        //move to right subtree
        {
            parent=current;
            current=current->left;
        }
    }
}

void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d", r->info);
        inorder(r->right);
    }
}

void preOrder(struct node *r)
{
    if(r!=NULL)
    {
        printf("%d", r->info);
        inorder(r->left);   
        inorder(r->right);
    }
}

void postOrder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);   
        inorder(r->right);
        printf("%d", r->info);
    }
}


int main()
{
    char choice;
    root=NULL;
    do
    {
        /* code */
        printf("Select an Option: \n");
        printf("\n1. Insert Item \n2. Remove Item \n3. Inorder Traverse");
        printf("\n4. Preorder Traverse \n5. Postorder Traverse \n6. Search Item");
        printf("\n7. Exit");
        fflush(stdin);
        choice=getch();
        switch(choice)
        {
            case '1':
                bstInsert();
                break;

            case '2':

                break;

            case '3':
                inorder(root);
                break;

            case '4':
                preOrder(root);
                break;

            case '5':
                postOrder(root);
                break;

            case '6':
                break;

            case '7':
                return 0;

            default:
                printf("Please Enter a Valid Choice.\n");
        }
        getch();
    } while (1);
    
}