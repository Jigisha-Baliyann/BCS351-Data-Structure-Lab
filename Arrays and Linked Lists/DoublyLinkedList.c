#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to display the elements of the doubly linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("Doubly Linked List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a new element at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element %d\n", value);
        return head;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    printf("Element %d inserted at the beginning\n", value);
    return head;
}

// Function to insert a new element at the end of the doubly linked list
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element %d\n", value);
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty, make the new node the head
        newNode->prev = NULL;
        head = newNode;
    } else {
        // Otherwise, traverse to the end and append the new node
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        newNode->prev = current;
        current->next = newNode;
    }

    printf("Element %d inserted at the end\n", value);
    return head;
}

// Function to insert a new element at a specified position in the doubly linked list
struct Node* insertAtPosition(struct Node *head, int value, int position) {
    if (position < 0) {
        printf("Invalid position. Cannot insert element %d\n", value);
        return head;
    }

    if (position == 0) {
        // Insert at the beginning if position is 0
        return insertAtBeginning(head, value);
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element %d\n", value);
        return head;
    }

    newNode->data = value;

    // Traverse to the position just before the specified position
    struct Node *current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        // If the position is beyond the end of the list, insert at the end
        free(newNode);
        return insertAtEnd(head, value);
    }

    newNode->prev = current;
    newNode->next = current->next;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;

    printf("Element %d inserted at position %d\n", value, position);
    return head;
}

// Function to delete the first element from the doubly linked list
struct Node* deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete from the beginning\n");
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);

    printf("Element from the beginning deleted\n");
    return head;
}

// Function to delete the last element from the doubly linked list
struct Node* deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete from the end\n");
        return head;
    }

    if (head->next == NULL) {
        // If there is only one element, delete it and set head to NULL
        free(head);
        head = NULL;
    } else {
        // Otherwise, traverse to the end and delete the last node
        struct Node *current = head;
       
