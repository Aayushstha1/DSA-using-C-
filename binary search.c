#include <stdio.h> 

int binarySearch(int arr[], int size, int targetVal);

int main() {
    int myArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int myTarget = 15;
    int size = sizeof(myArray) / sizeof(myArray[0]);

    int result = binarySearch(myArray, size, myTarget);

    if (result != -1) {
        printf("Value %d found at index %d\n", myTarget, result);
    } else {
        printf("Target not found in array.\n");
    }

    return 0;
}

int binarySearch(int arr[], int size, int targetVal) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == targetVal) {
            return mid;
        }

        if (arr[mid] < targetVal) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
