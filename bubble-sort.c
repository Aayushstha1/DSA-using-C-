#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void bubblesort(int[], int);
void main()
{
    int arr[] = {13, 23, 3, 35, 56, 12, 46, 63, 93, 23, 1, 23, 0};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before sorting ...\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    bubblesort(arr,n);
    printf("\nAfter sorting ...\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for(j=0; j<n-1; j++) {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}