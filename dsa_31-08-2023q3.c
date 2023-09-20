#include <stdio.h>

#define MAX_SIZE 100

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void PUSH(int stack[], int value, int *top) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }
    *top += 1;
    stack[*top] = value;
}

int POP(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow.\n");
        return -1; 
    }
    int value = stack[*top];
    *top -= 1;
    return value;
}

void enqueue(int value) {
    PUSH(stack1, value, &top1);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return -1; 
    }

    if (top2 == -1) {
        while (top1 != -1) {
            int value = POP(stack1, &top1);
            PUSH(stack2, value, &top2);
        }
    }

    return POP(stack2, &top2);
}

void displayQueue() {
    printf("Queue contents: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}
