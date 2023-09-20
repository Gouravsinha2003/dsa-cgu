#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1,i;

void push(int value) 
{
    if (top == MAX_SIZE - 1) 
	{
        printf("Stack is full. \n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop() 
{
    if (top == -1) 
	{
        printf("Stack is empty. \n");
    } else 
	{
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}
void peek() 
{
    if (top == -1) 
	{
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() 
{
    if (top == -1) 
	{
        printf("Stack is empty.\n");
    } else 
	{
        printf("Stack contents:\n");
        for (i = top; i >= 0; i--) 
		{
            printf("%d\n", stack[i]);
        }
    }
}
int main() 
{
    int choice, value;

    do 
	{
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
}
