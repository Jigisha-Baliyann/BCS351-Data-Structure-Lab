#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a double-ended queue
struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize a double-ended queue
void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque) {
    return deque->front == -1 && deque->rear == -1;
}

// Function to check if the deque is full
int isFull(struct Deque *deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = value;
    printf("Inserted %d at the front of the deque.\n", value);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = value;
    printf("Inserted %d at the rear of the deque.\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    if (deque->front == deque->rear) {
        // If there is only one element in the deque
        printf("Deleted %d from the front of the deque.\n", deque->arr[deque->front]);
        deque->front = -1;
        deque->rear = -1;
    } else {
        printf("Deleted %d from the front of the deque.\n", deque->arr[deque->front]);
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }

    if (deque->front == deque->rear) {
        // If there is only one element in the deque
        printf("Deleted %d from the rear of the deque.\n", deque->arr[deque->rear]);
        deque->front = -1;
        deque->rear = -1;
    } else {
        printf("Deleted %d from the rear of the deque.\n", deque->arr[deque->rear]);
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

// Function to get the front element of the deque
int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No front element.\n");
        return -1; // Assuming -1 as an invalid value for an element
    }

    return deque->arr[deque->front];
}

// Function to get the rear element of the deque
int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No rear element.\n");
        return -1; // Assuming -1 as an invalid value for an element
    }

    return deque->arr[deque->rear];
}

// Function to display the elements of the deque
void displayDeque(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    do {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Deque myDeque;
    initializeDeque(&myDeque);

    insertFront(&myDeque, 10);
    insertRear(&myDeque, 20);
    insertFront(&myDeque, 5);

    displayDeque(&myDeque);

    printf("Front element: %d\n", getFront(&myDeque));
    printf("Rear element: %d\n", getRear(&myDeque));

    deleteFront(&myDeque);
    deleteRear(&myDeque);

    displayDeque(&myDeque);

    return 0;
}
