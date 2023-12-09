#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            low = mid + 1;
        }

        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("\n%d found at index %d\n", target, result);
    } else {
        printf("\n%d not found in the array\n", target);
    }

    return 0;
}
