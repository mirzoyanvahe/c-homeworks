#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to append a new node at the end of the list
void append(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert a new node at a specified position in the list
void insert(struct Node** head, int position, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to get the value at a specified position in the list
int get(struct Node* head, int position) {
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return -1; // Assuming -1 as an indicator for an error or not found
    }

    return temp->data;
}

// Function to delete a node at a specified position in the list
void delete(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Function to print the elements of the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Test the functions
int main() {
    struct Node* list = NULL;

    // Append elements to the list
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);

    printf("Original list: ");
    printList(list);

    // Insert an element at position 1
    insert(&list, 1, 4);
    printf("After inserting 4 at position 1: ");
    printList(list);

    // Get the value at position 2
    int value = get(list, 2);
    printf("Value at position 2: %d\n", value);

    // Delete the element at position 1
    delete(&list, 1);
    printf("After deleting element at position 1: ");
    printList(list);

    // Free the memory used by the list
    while (list != NULL) {
        struct Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
