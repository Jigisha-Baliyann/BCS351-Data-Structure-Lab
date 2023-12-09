#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            // Element found, return its index
            return i;
        }
    }

    // Element not found
    return -1;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("\n%d found at index %d\n", target, result);
    } else {
        printf("\n%d not found in the array\n", target);
    }

    return 0;
}
