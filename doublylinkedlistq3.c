#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to reverse a doubly linked list
void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        // Swap "prev" and "next" pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node
        current = current->prev;
    }

    // Update the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insertions
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Display the original list
    printf("Doubly Linked List (Original): ");
    displayList(head);

    // Reverse the doubly linked list
    reverseList(&head);

    // Display the reversed list
    printf("Doubly Linked List (Reversed): ");
    displayList(head);

    return 0;
}
