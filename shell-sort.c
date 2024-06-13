#include <stdio.h>
#include <conio.h>
void shellsort(int arr[],int n)
{
    int i,j,temp,gap;
    for(gap=n/2;gap>0;gap=gap/2)
    {
        for(i=gap;i<n;i++)
    {
        temp=arr[i];
        for(j=i-gap;j>=0 && arr[j]>temp;j=j-gap)
        arr[j+gap]=arr[j];
        arr[j+gap]=temp;
    }
}
    }
void main()
{
    
    int arr[] = {15,12,4,11,6,7,9,4,5,2};
    int n = sizeof(arr) / sizeof(int);

    printf("Before sorting ....\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    shellsort(arr,n);

    printf("\nAfter sorting ....\n");
    for (int i=0; i < n; i++)
        printf("%d\t", arr[i]);

    getch();
    
}
