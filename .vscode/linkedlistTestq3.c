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


struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }

    return mergedList;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 5);

    
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);

    printf("First Linked List: ");
    display(list1);

    printf("Second Linked List: ");
    display(list2);

    
    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged Linked List: ");
    display(mergedList);

    return 0;
}
