#include<stdio.h>
#include<conio.h>
#define MAX 10
void mergesort (int arr[], int lb, int ub ,int mid)
{
    int temp[MAX];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=0;

    while(i<=mid && j<=ub)// untill one list is finished
    {
        if(arr[i]<=arr[j])// if ith element of first sublist is smaller than jth element of second sublist then copy from first sublist
        {
            temp[k]=arr[i];
            i++;
             }
             else
             {
                temp[k]=arr[j];
                j++;
             }
             k++;
    }
    while(i<=mid)//copy all remaining from the first sublist if any 
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j=ub)//copy all remaining from the first sublist if any 
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=lb,k=0;)
}


void mergesort (int arr[], int lb, int ub)
{
    int mid=(lb+ub)/2;
    if(lb<ub)
    {
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        mergesort(arr,lb,mid,ub);
    }
}
void main()
{
    int arr[]={22,18,9,4,6,3,11,5,2,8};
        int i;
        printf("Before sorting ..... \n");
        for(i=0;i<MAX;i++)
        printf("%d\t", arr[i]);
        mergesort (arr,0,MAX-1);
        printf("\nAfter  sorting ..... \n");
        for(i=0;i<MAX;i++)
        printf("%d\t", arr[i]);
getch();
} 
