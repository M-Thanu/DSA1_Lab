#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top=-1;

int isFull(){
    return top == MAX-1;
}

int isEmpty(){
    return top == -1;
}

void display(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    int c=top;
    while(c !=-1){
        printf("%d\t",stack[c]);
        c--;
    }
}

void push(int value){
    if(isFull()){
        printf("Stack is full");
    }
    top=top+1;
    stack[top]=value;
    display();
}

void pop(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    top=top-1;
    display();
}

void peek(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    printf("Top: %d",stack[top]);
}

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


