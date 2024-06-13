#include <stdio.h>
#include <conio.h>

#define MAX 20

int getHighestNumber(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int getDigitCount(int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

void countsort(int arr[], int n, int place) {
    int count[10] = {0};
    int temp[MAX];
    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        temp[--count[(arr[i] / place) % 10]] = arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void radixsort(int arr[], int n) {
    int digitCount = getDigitCount(getHighestNumber(arr, n));
    int place = 1;
    for (int i = 1; i <= digitCount; i++, place *= 10)
        countsort(arr, n, place);
}

int main() {
    int arr[] = {77, 82, 33, 15, 108, 28, 39, 11, 51, 49};
    int n = sizeof(arr) / sizeof(int);

    printf("Before sorting ....\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    radixsort(arr, n);

    printf("\nAfter sorting ....\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    getch();
    return 0;
}
