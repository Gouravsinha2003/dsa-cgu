#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

bool isEmpty() {
    return (front == -1);
}

void CQINSERT(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    circularQueue[rear] = value;
    printf("%d inserted successfully.\n", value);
}
void CQDELETE() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    int deletedValue = circularQueue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    printf("%d deleted successfully.\n", deletedValue);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                CQINSERT(value);
                break;
            case 2:
                CQDELETE();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
       }
    }

}
