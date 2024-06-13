#include<stdio.h>
#include<conio.h>
int linearsearch(int arr[],int n,int key)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(arr[i]==key)
 {
return i;
}
 }
 return -1;
}
void main()
{
    int arr[]={12,45,2,7,11,65,9,4,3,15};
    int i,n=sizeof(arr)/sizeof(int);
    int key;
    printf("Enter a number u want to search:");
    scanf("%d",&key);
    i=linearsearch(arr,n,key);
    if(i==-1)
    printf("%d does not exit in the list.",key);
    else
        printf("%d found at the list.",key+1);

}
