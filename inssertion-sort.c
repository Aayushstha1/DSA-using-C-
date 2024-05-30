#include <stdio.h>
#include <conio.h>

void insertionSort(int arr[], int i, int j)
{
    int k, temp, key;
    for (k = i + 1; k <= j; k++) // insert all elements from i=1 to j into the already sorted list.
    {
        key = arr[k]; // insert items at kth position
        temp = k - 1;//start from just one position left of key
        while (temp>=0 && arr[temp]>key)
        {
            arr[temp + 1] = arr[temp]; //move to right position
            temp--;
        }
        arr[temp + 1] = key;//insert key into its final position
    }
}

void main()
{
    int arr[] = {20, 40, 3, 8, 34, 66, 9};
    int i, n = sizeof(arr) / sizeof(int);

    printf("Before soring..............\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    insertionSort(arr, 0, n - 1);

    printf("\nAfter Sorting...............\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    getch();
}