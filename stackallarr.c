#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Push operation
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is empty! Nothing to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
            if (isEmpty())
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 5:
            if (isFull())
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
