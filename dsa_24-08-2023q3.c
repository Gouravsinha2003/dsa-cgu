#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %c.\n", value);
    } else {
        stack->items[++stack->top] = value;
    }
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    char inputString[MAX_SIZE];
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from the input
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(inputString); i++) {
        push(&stack, inputString[i]);
    }

    // Pop and print characters to reverse the string
    printf("Reversed string: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
