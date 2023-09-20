#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the sum of all elements in the linked list
int findSum(struct Node* head) {
    int sum = 0;
    struct Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the initial linked list: 10 -> 30 -> 20 -> 40 -> 50
    struct Node* head = createNode(10);
    head->next = createNode(30);
    head->next->next = createNode(20);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Initial Linked List: ");
    printList(head);

    int sum = findSum(head);

    printf("Sum of all elements in the linked list: %d\n", sum);

    // Free the memory used by the linked list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
