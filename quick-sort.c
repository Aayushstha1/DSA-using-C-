#include<stdio.h>
#include<conio.h>
void quicksort (int arr[], int lb, int ub)
{
    int down=lb,up=ub,pivot=arr[lb],temp;
    while (down<up)
    {
        
        while(down<ub && arr[down]<=pivot)
        down++;
        while (arr[up]>pivot)
        up--;
        if(down<up)
        {
            temp=arr[down];
            arr[down]=arr[up];
            arr[up]=temp;
        }
        else {
            temp=arr[lb];
            arr[lb]=arr[up];
            arr[up]=temp;
            quicksort(arr,lb,up-1);
            quicksort(arr,up+1,ub);
             }
    }
}
void main ()
{
    int arr[]={12,4,5,2,7,9,11,10,6,3};
    int i,n=sizeof(arr)/sizeof(int);
    printf("Before sorting...\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    quicksort(arr,0,n-1);
    printf("\nAfter sorting...\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    quicksort(arr,0,n-1);
    }