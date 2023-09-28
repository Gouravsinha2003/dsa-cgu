#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void deleteFirstAndMoveToEnd(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        
        return;
    }

    struct Node* firstNode = *head;
    *head = firstNode->next;
    (*head)->prev = NULL;

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = firstNode;
    firstNode->prev = current;
    firstNode->next = NULL;
}


void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original Doubly Linked List: ");
    display(head);

    
    deleteFirstAndMoveToEnd(&head);

    printf("Modified Doubly Linked List: ");
    display(head);

    return 0;
}
