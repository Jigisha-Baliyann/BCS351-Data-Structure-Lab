#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the stack
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent the stack
struct Stack {
    struct Node *top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push %d\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Returning a sentinel value for simplicity
    }

    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);

    printf("%d popped from the stack\n", popped);
    return popped;
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        struct Node *current = stack->top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free memory allocated for the stack nodes
void cleanup(struct Stack *stack) {
    while (stack->top != NULL) {
        struct Node *temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    pop(&stack);
    display(&stack);

    // Free allocated memory before exiting the program
    cleanup(&stack);

    return 0;
}
