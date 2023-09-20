#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() 
{
    return rear == MAX_SIZE - 1;
}

int isEmpty() 
{
    return front == -1;
}

void enqueue(int data)
{
    if (isFull()) 
	{
        printf("Queue is full. Cannot insert.\n");
        return;
    }
    
    if (isEmpty()) 
	{
        front = rear = 0;
    } else 
	{
        rear++;
    }
    
    queue[rear] = data;
    printf("%d inserted into the queue.\n", data);
}

void dequeue() 
{
    if (isEmpty()) 
	{
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    
    int deleted = queue[front];
    
    if (front == rear) 
	{
        front = rear = -1;
    } else 
	{
        front++;
    }
    
    printf("%d deleted from the queue.\n", deleted);
}

void traverse() 
{
    if (isEmpty()) 
	{
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
	{
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, data;
    
    while (1) 
	{
        printf("\nLinear Queue Menu:\n");
        printf("1. Enqueue (Insertion)\n");
        printf("2. Dequeue (Deletion)\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
   return 0;
}
