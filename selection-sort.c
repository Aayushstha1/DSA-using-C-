// worst case time complexity:O(n^2)
//Best case time complexity :  O(n^2)
#include<stdio.h>
#include<conio.h>
int getSmallestposition(int arr[],int i ,int j)
{          
    int pos=i,k;
    for(k=i;k<=j;k++)
    if(arr[k]<arr[pos])
    
        pos=k;
        return pos;
    
}
void selectionSort(int arr[], int n)
{
    int i,smallestposition,temp;
    for(i=0;i<n-1;i++){
        smallestposition=getSmallestposition(arr,i,n-1);
        temp=arr[i];
        arr[i]=arr[smallestposition];
        arr[smallestposition]=temp;
    }
}
void main ()
{
    int arr[]={5,12,6,2,7,9,10,4};
    int i,n=sizeof(arr)/sizeof(int);

    printf("Before sorting....\n");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    selectionSort(arr,n);
     printf("\nAfter sorting....\n");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    getch();
}
