#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to display the elements of the circular linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to insert a new element at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element %d\n", value);
        return head;
    }

    newNode->data = value;
    newNode->next = newNode; // Point to itself initially

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Otherwise, traverse to the end and link the last node to the new node
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head; // Make the new node circular
        head = newNode; // Update the head to the new node
    }

    printf("Element %d inserted at the beginning\n", value);
    return head;
}

// Function to insert a new element at the end of the circular linked list
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element %d\n", value);
        return head;
    }

    newNode->data = value;
    newNode->next = newNode; // Point to itself initially

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Otherwise, traverse to the end and link the last node to the new node
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head; // Make the new node circular
    }

    printf("Element %d inserted at the end\n", value);
    return head;
}

// Function to insert a new element at a specified position in the circular linked list
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
    for (int i = 1; i < position && current->next != head; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Element %d inserted at position %d\n", value, position);
    return head;
}

// Function to delete the first element from the circular linked list
struct Node* deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete from the beginning\n");
        return head;
    }

    struct Node *temp = head;
    if (head->next == head) {
        // If there is only one element, delete it and set head to NULL
        free(head);
        head = NULL;
    } else {
        // Otherwise, traverse to the end, update the last node's next pointer
        // and delete the first node
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        head = head->next;
        free(temp);
    }

    printf("Element from the beginning deleted\n");
    return head;
}

// Function to delete the last element from the circular linked list
struct Node* deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete from the end\n");
        return head;
    }

    struct Node *temp = head;
    if (head->next == head) {
        // If there is only one element, delete it and set head to NULL
        free(head);
        head = NULL;
    } else {
        // Otherwise, traverse to the end, update the last node's next pointer
        // and delete the last node
        struct Node *current = head;
        while (current->next->next != head) {
            current = current->next;
        }
        temp = current->next;
        current->next = head;
        free(temp);
    }

    printf("Element from the end deleted\n");
    return head;
}

// Function to delete an element from a specified position in the circular linked list
struct Node* deleteFromPosition(struct Node *head, int position) {
    if (head == NULL || position < 0) {
        printf("Invalid position. Cannot delete element\n");
        return head;
    }

    if (position == 0) {
        // Delete from the beginning if position is 0
        return deleteFromBeginning(head);
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    for (int i = 0; i < position && current->next != head; i++) {
        previous = current;
        current = current->next;
    }

    if (current == head) {
        // If the position is beyond the end of the list, do nothing
        printf("Position %d is beyond the end of the list. Cannot delete element\n", position);
        return head;
    }

    previous->next = current->next;
    free(current);

    printf("Element from position %d deleted\n", position);
    return head;
}

// Function to free memory allocated for the circular linked list nodes
void cleanup(struct Node *head) {
    if (head == NULL) {
        return;
    }

    struct Node *current = head;
    struct Node *nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    struct Node *head = NULL;

    // Inserting elements into the circular linked list
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtPosition(head, 15, 1);

    // Displaying the circular linked list
    displayList(head);

    // Deleting elements from the circular linked list
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteFromPosition(head, 0);

    // Displaying the updated circular linked list
    displayList(head);

    // Free allocated memory before exiting the program
    cleanup(head);

    return 0;
}
