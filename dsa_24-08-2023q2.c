#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int value) 
{
    if (top >= MAX_SIZE-1) 
	{
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto the stack\n", value);
}

void pop() 
{
    if (top < 0) 
	{
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    printf("Popped %d from the stack\n", stack[top--]);
}
void peek() 
{
    if (top < 0) 
	{
        printf("Stack is empty. Cannot peek.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}


void display() 
{
    if (top < 0) 
	{
        printf("Stack is empty. Nothing to display.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) 
	{
        printf("%d\n", stack[i]);
    }
}
int main() 
{
    push(6);
    push(7);
    push(8);
    push(5);
    push(3);
    push(10);
    pop();
    pop();
    display();

}


