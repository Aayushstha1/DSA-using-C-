#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int queue[MAXSIZE], rare=-1,front=0;

int main(){
    int choice;

    do{

        printf("\n=========Queu Implementation==========\n");
        printf("\n1.Insert\n2.Delete\n3.Display\n");
        printf("\n=======================================\n");

        printf("\nChoose: ");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:insert();break;
        case 2:delete1();break;
        case 3:display();break;

        }

    }while(choice!=4);

}

int insert(){
    int n;
    if(rare==MAXSIZE-1)
       printf("Queue is overflow");
    else
       printf("enter the element: ");
       scanf("%d",&n);
       rare++;
       queue[rare]=n;
}

int delete1(){
    int n; 
    if(front>rare)
        printf("queue is Empty.");

    else
       n= queue[front];
       front++;
       printf("Deleted element is %d",n);
}

int display(){
    int i;
    for(i=front; i<=rare; i++){
        printf("%5d",queue[i]);
    }
}