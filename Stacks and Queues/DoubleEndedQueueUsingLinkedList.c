#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the deque
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Structure to represent a double-ended queue
struct Deque {
    struct Node *front;
    struct Node *rear;
};

// Function to initialize a double-ended queue
void initializeDeque(struct Deque *deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque) {
    return deque->front == NULL && deque->rear == NULL;
}

// Function to create a new node with given data
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    struct Node *newNode = createNode(value);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("Inserted %d at the front of the deque.\n", value);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    struct Node *newNode = createNode(value);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("Inserted %d at the rear of the deque.\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    struct Node *temp = deque->front;

    if (deque->front == deque->rear) {
        // If there is only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    printf("Deleted %d from the front of the deque.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }

    struct Node *temp = deque->rear;

    if (deque->front == deque->rear) {
        // If there is only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    printf("Deleted %d from the rear of the deque.\n", temp->data);
    free(temp);
}

// Function to get the front element of the deque
int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No front element.\n");
        exit(EXIT_FAILURE);
    }

    return deque->front->data;
}

// Function to get the rear element of the deque
int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No rear element.\n");
        exit(EXIT_FAILURE);
    }

    return deque->rear->data;
}

// Function to display the elements of the deque
void displayDeque(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    struct Node *current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to cleanup and free memory allocated for the deque nodes
void cleanup(struct Deque *deque) {
    struct Node *current = deque->front;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    // Reset deque to an empty state
    deque->front = NULL;
    deque->rear = NULL;
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

    // Free allocated memory before exiting the program
    cleanup(&myDeque);

    return 0;
}
