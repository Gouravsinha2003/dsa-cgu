#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


int countNonZeroElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data != 0) {
            count++;
        }
        current = current->next;
    }
    return count;
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

    
    insert(&head, 0);
    insert(&head, 2);
    insert(&head, 0);
    insert(&head, 4);
    insert(&head, 0);

    printf("Linked List: ");
    display(head);

    
    int nonZeroCount = countNonZeroElements(head);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    return 0;
}
