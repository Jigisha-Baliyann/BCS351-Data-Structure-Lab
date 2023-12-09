#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent the queue
struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued into the queue\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1; // Returning a sentinel value for simplicity
    }

    struct Node *temp = queue->front;
    int dequeued = temp->data;
    queue->front = temp->next;
    free(temp);

    printf("%d dequeued from the queue\n", dequeued);
    return dequeued;
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        struct Node *current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free memory allocated for the queue nodes
void cleanup(struct Queue *queue) {
    while (queue->front != NULL) {
        struct Node *temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    dequeue(&queue);
    display(&queue);

    // Free allocated memory before exiting the program
    cleanup(&queue);

    return 0;
}
