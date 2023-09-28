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

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    int currentPosition = 1;
    
    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }
    
    if (currentPosition == position - 1) {
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    } else {
        printf("Invalid position for insertion.\n");
        free(newNode);
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
    insertAtPosition(&head, 10, 1); // Insert 10 at position 1
    insertAtPosition(&head, 20, 2); // Insert 20 at position 2
    insertAtPosition(&head, 30, 3); // Insert 30 at position 3
    insertAtPosition(&head, 40, 4); // Insert 40 at position 4
    
    // Display the list
    printf("Doubly Linked List: ");
    displayList(head);
    
    return 0;
}
