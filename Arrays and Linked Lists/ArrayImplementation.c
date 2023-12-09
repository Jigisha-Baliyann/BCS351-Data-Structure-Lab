#include <stdio.h>

#define MAX_SIZE 100

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position in the array
void insertElement(int arr[], int *size, int position, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert element %d\n", element);
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot insert element %d\n", element);
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position
    arr[position] = element;

    // Increment the size of the array
    (*size)++;

    printf("Element %d inserted at position %d\n", element, position);
}

// Function to delete an element at a specified position in the array
void deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete element\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position. Cannot delete element\n");
        return;
    }

    // Shift elements to the left to fill the gap created by the deleted element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array
    (*size)--;

    printf("Element at position %d deleted\n", position);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Inserting elements into the array
    insertElement(arr, &size, 0, 10);
    insertElement(arr, &size, 1, 20);
    insertElement(arr, &size, 2, 30);

    // Displaying the array
    displayArray(arr, size);

    // Deleting an element from the array
    deleteElement(arr, &size, 1);

    // Displaying the updated array
    displayArray(arr, size);

    return 0;
}
