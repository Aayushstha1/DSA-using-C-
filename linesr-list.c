//doubly linear list implementation using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*prev;
	struct node*next;
};
struct node*header;//declare external pointer header that points to the list
struct node*getNode(int data)
{
	struct node*ptrnew;
	ptrnew=(struct node*)malloc(sizeof(struct node));
	if(ptrnew==NULL)
	{
		printf("\nMemory allocation failed.");
		getch();
		exit(0);
	}
	ptrnew->info=data;
	ptrnew->prev=ptrnew->next=NULL;
	return ptrnew;
}
void insertAtEnd()
{
	int data;
	struct node*newNode,*ptrthis;
	printf("Enter a number:");
	scanf("%d",&data);
	newNode=getNode(data);
	if(header==NULL)//empty list
	{
		header=newNode;
		printf("Inserted at the front.");
	}
	else{
		for(ptrthis=header;ptrthis->next!=NULL;ptrthis=ptrthis->next)//move to last node
		ptrthis->next=newNode;
		newNode->prev=ptrthis;
		printf("Inserted at the end.");
	}
}
void insertAtFront()
{
	int data;
	struct node*newNode,ptrthis;
	printf("Enter a number:");
	scanf("%d",&data);
	newNode=getNode(data);
	if(header==NULL)//empty list
	header=newNode;
	else{
		newNode->next=header;
		header->prev=newNode;
		header=newNode;
	}
	printf("Inserted at the front");
}
void insertAfter()
{
	struct node*newNode,*ptrthis;
	int data,key;
	if(header==NULL)
	printf("List is empty.");
	else
	{
		printf("Enter a key number after which you want to insert new node:");
		scanf("%d",&key);
		for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
		{
			if(ptrthis->info==key)//if node found
			{
				printf("Enter the number:");
				scanf("%d",&data);
				newNode=getNode(data);
				newNode->next=ptrthis->next;
				newNode->pre=ptrthis;
				if(ptrthis->next!=NULL)//if we are adding in the middle
				(ptrthis->next)->prev=newNode;
				ptrthis->next=newNode;
				printf("Inserted after %d",ptrthis->info);
				return;
			}
		}
		printf("Node not found with key value %d",key);
	}
}
void removeFromFront()
{
	int data;
	if(header==NULL)
	printf("List is empty.");
	else 
	{
		data=header->info;
	    if(header->next==NULL)//if single item in the list
	{
		free(header);
		header=NULL;
	}
	else
	{
		header=header->next;
		free(header->prev);
		header->prev=NULL;
	}
	printf("%d was removed from the front.",data);
}
}
void display()
{
	struct node*ptrthis;
	if(header==NULL)
	printf("List is empty.");
	else
	{
		printf("\nList contains:\n");
		for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
		printf("%d\t",ptrthis->info);
	}
}
void main()
{
	char choice;
	header=NULL;//initialize empty list
	do{
		
		printf("Select your choice:");
		printf("\n1. Insert at front \n2.Insert at END \n3. Remove from END \n4 Remove from Front \n4. Display\n5. Exit");
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case'1':insertAtEnd();break;
			case'2':removeFromFront();break;
			case'3':display();break;
			case'4':return;
			default:printf("wrong selection. Try again!");
		}
		getch();
	}while(1);
}