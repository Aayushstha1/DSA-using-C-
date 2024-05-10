#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*father;
    struct node*left;
    struct node*right;
};
struct node*root;


struct node *ptrnew;
ptrnew=(struct node*)malloc(sizeof(struct));
if(prtmew==NULL)
{
}





void bstInsert()
{
    int n;
    struct node*ptrnew, *curr=root, *parent=NULL;
    printf("\nEnter a number:");
    scanf("%d",&n);
    ptrnew=getnode(n);
    while(1)
    {
        if(curr==NULL)//it is time to insert new node
        {
               if(root==NULL)
               {
                root=ptrnew;
                printf("%d inserted as the root node",n);
               }
               else
               {
                if(n<parent->info)//insert as the left son
                {
                    parent->left=ptrnew;
                    printf("%d is inserted as the left son of %d",n,parent->info);

                }
                else
                {
                    parent->right=ptrnew;
                    printf("%d inserted as the right son of %d",n,parent->info);
                }
                ptrnew->father=parent
               }
               return;
        }
        else if (n<curr->info)
        {
            parent=curr;
            curr=curr->left;
        }
        else
        {
            parent=curr;
            curr=curr->right;
        }
    }

}
void inorder(struct node*r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("\t%d",r->info);
        inorder(r->right);
    }
}
void preorder (struct node*r)
{
    if(r!=NULL)
    {
        printf("\t%d",r->info);
        inorder(r->left);
        inorder(r->right);
        printf("\t%d",r->info);
    }
}
void main()
{
    char choice;
    root=NULL;
    do{
        clrscr();
        printf("Select an option");
        printf("\n1. Insert item\n2.REMOVE ITEM. \n3. Insert Traversal");
        printf("\n4. Pre-order Traversal\n5.post-order Traversal.\n6. search item");
        printf("\n7 Exit.");
        fflush(stdin);
        choice=getch();
        switch(choice)
        {
            case '1': bstInsert();break;
             case '2':break;
             case '3':inorder(root);break;
             case '4':preorder(root); break;
             case '5':postorder(root); break
             case '6':

        }

    }
}