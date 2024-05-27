//size of data directly hamp
// BIG(O) aaila samma sabai vandha dharai chala ko 
// determine factor size of.
// n^2  
// average case (n+n^2)/2;

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void bubblesort(int[] , int );
void main()
{
    int arr[]={13,21,5,62,12,6,7,23,8,10};
    int i,n=sizeof(arr)/sizeof(int);
    printf("Before sorting ...\n");
    for(i=0;i<n;i++)
    printf(" %d\t", arr[i]);
    bubblesort(arr,n);
    printf("After sorting..\n");
    for(i=0;i<n;i++)      
    printf(" %d\t", arr[i]);
    getch();
}
void bubblesort(int arr[],int n)
{
    int i,j, temp;
    for(i=0;i<n-1;i++)
    {
            for(j=0;i<j-1;j++)
            {
                if(arr[j]>arr [j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                }

            }

    }
}