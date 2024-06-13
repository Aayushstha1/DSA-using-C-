#include<stdio.h>
#include<conio.h>
#define MAX 20
int getHighestNumber(int arr[],int n)
{
    int max,i;
    max=arr[0];
    for(i=1;i<n;i++)
    if(arr[i]>max)
    max=arr[i];
    return max;
}
void getDigitCount(int n)
{
    int count=0;
    while(n>0)
    {
        n=n/10;
        count++;
    }
    return count;
}
void countsort(int arr[],int n, int place)
{
    int count[10]={0};
    int temp[MAX];
    int i;
    for(i=0;i<n;i++)
    count[(arr[i]/place)%10]++;
    for(i=1;i<10;i++)
    count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--)
   temp[--count[(arr[i]/place)%10]]=arr[i]; 
   for(i=0;i<n;i++)
   arr[i]=temp[i];
}
void radixsort(int arr[],int n)
{
 int digitCount=getDigitCount(getHighestNumber(arr,n));
 int i,place=1;
 for (i=1;i<=digitCount;i++,place=place*10)
 countsort(arr,n,place);
}
void main()
{
    int arr[]={77,82,33,15,108,28,39,11,51,49};
    int i,n=sizeof(arr)/sizeof(int);
    printf("Before sorting ....\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    radixsort(arr,n);
      printf("After sorting ....\n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    getch();
}