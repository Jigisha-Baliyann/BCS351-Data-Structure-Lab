#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular queue
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent the circular queue
struct CircularQueue {
    struct Node *front;
    struct Node *rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *cqueue) {
    cqueue->front = cqueue->rear = NULL;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *cqueue) {
    return cqueue->front == NULL;
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue *cqueue, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(cqueue)) {
        cqueue->front = cqueue->rear = newNode;
    } else {
        cqueue->rear->next = newNode;
        cqueue->rear = newNode;
    }

    // Make the queue circular
    cqueue->rear->next = cqueue->front;

    printf("%d enqueued into the circular queue\n", value);
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue *cqueue) {
    if (isEmpty(cqueue)) {
        printf("Circular Queue Underflow! Cannot dequeue from an empty circular queue\n");
        return -1; // Returning a sentinel value for simplicity
    }

    int dequeued = cqueue->front->data;

    if (cqueue->front == cqueue->rear) {
        // Last element in the circular queue, reset front and rear
        free(cqueue->front);
        cqueue->front = cqueue->rear = NULL;
    } else {
        struct Node *temp = cqueue->front;
        cqueue->front = cqueue->front->next;
        cqueue->rear->next = cqueue->front;
        free(temp);
    }

    printf("%d dequeued from the circular queue\n", dequeued);
    return dequeued;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *cqueue) {
    if (isEmpty(cqueue)) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        struct Node *current = cqueue->front;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != cqueue->front);
        printf("\n");
    }
}

// Function to free memory allocated for the circular queue nodes
void cleanup(struct CircularQueue *cqueue) {
    while (cqueue->front != NULL) {
        struct Node *temp = cqueue->front;
        cqueue->front = cqueue->front->next;
        free(temp);
    }
}

int main() {
    struct CircularQueue cqueue;
    initialize(&cqueue);

    enqueue(&cqueue, 10);
    enqueue(&cqueue, 20);
    enqueue(&cqueue, 30);

    display(&cqueue);

    dequeue(&cqueue);
    display(&cqueue);

    // Free allocated memory before exiting the program
    cleanup(&cqueue);

    return 0;
}
