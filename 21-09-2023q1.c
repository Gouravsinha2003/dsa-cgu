#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    if (position < 1) {
        printf("Invalid position. Position must be greater than or equal to 1.\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    insertAtPosition(&head, 10, 1); // Insert 10 at position 1 (at the beginning)
    insertAtPosition(&head, 20, 2); // Insert 20 at position 2
    insertAtPosition(&head, 30, 3); // Insert 30 at position 3
    insertAtPosition(&head, 40, 4); // Insert 40 at position 4 (at the end)


    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}
