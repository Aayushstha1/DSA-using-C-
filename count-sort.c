#include<stdio.h>
#include<conio.h>
#define SIZE 15
#define MAXVALUE 21
int getHighestNumber(int arr[],int n)
{
    int max=arr[0];
    int i;
    for(i=1;i<n;i++)
    if(arr[i]>max)
    max=arr[i];
    return max;
}
void countsort(int arr[],int n )
{
    int count[MAXVALUE]={0};
    int temp[SIZE];
    int k=getHighestNumber(arr,n);
    int i;
    //Perform frequency count of each number in the array 
    for (i=0;i<n;i++)
    count[arr[i]]++;
    // then calculate cumulatve frequency
    for(i=1;i<=k; i++)
    count[i]+=count[i-1];// count[i]=count[i]+count[i-1];
    //Now sort the items and put into temp arry .
    for(i=n-1;i>=0;i--)
    
        temp[--count[arr[i]]]=arr[i];
        // finally copy back the temp into arr
        for(i=0;i<n;i++)
        arr[i]=temp[i];
    }

void main()
{
    int arr[]={7,5,3,11,9,20,2,7,3,7}
    int i,n=sizeof(arr)/sizeof(int);
    printf("before sorting ................\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    countsort(arr,n);
    printf("After sorting ................\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    getch();
}
