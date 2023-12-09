#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *cqueue) {
    cqueue->front = -1;
    cqueue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *cqueue) {
    return cqueue->front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *cqueue) {
    return (cqueue->rear + 1) % MAX_SIZE == cqueue->front;
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue *cqueue, int value) {
    if (isFull(cqueue)) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(cqueue)) {
        cqueue->front = cqueue->rear = 0;
    } else {
        cqueue->rear = (cqueue->rear + 1) % MAX_SIZE;
    }

    cqueue->items[cqueue->rear] = value;
    printf("%d enqueued into the circular queue\n", value);
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue *cqueue) {
    if (isEmpty(cqueue)) {
        printf("Circular Queue Underflow! Cannot dequeue from an empty circular queue\n");
        return -1; // Returning a sentinel value for simplicity
    }

    int dequeued = cqueue->items[cqueue->front];

    if (cqueue->front == cqueue->rear) {
        // Last element in the circular queue, reset front and rear
        cqueue->front = cqueue->rear = -1;
    } else {
        cqueue->front = (cqueue->front + 1) % MAX_SIZE;
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
        int i = cqueue->front;
        do {
            printf("%d ", cqueue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cqueue->rear + 1) % MAX_SIZE);
        printf("\n");
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

    return 0;
}
