#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
    }

    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid + 1, right);
    }
    return inv;
}

// Helper to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Run test case
void runTest(int arr[], int n) {
    int temp[n];

    printf("Array: ");
    printArray(arr, n);

    long long inv = mergeSort(arr, temp, 0, n - 1);

    printf("Inversion Count: %lld\n", inv);
    printf("-----------------------------\n");
}

int main() {

    printf("=== Inversion Count Test Cases ===\n\n");

    // Test Case 1 (Normal)
    int arr1[] = {2, 4, 1, 3, 5};
    runTest(arr1, 5);

    // Test Case 2 (Sorted)
    int arr2[] = {1, 2, 3, 4, 5};
    runTest(arr2, 5);

    // Test Case 3 (Reverse sorted)
    int arr3[] = {5, 4, 3, 2, 1};
    runTest(arr3, 5);

    // Test Case 4 (Single element)
    int arr4[] = {10};
    runTest(arr4, 1);

    // Test Case 5 (Duplicates)
    int arr5[] = {1, 3, 2, 3, 1};
    runTest(arr5, 5);

    return 0;
}