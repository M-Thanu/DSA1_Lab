#include <stdio.h>
#include <stdlib.h>

#define mc 100 

int s_arr[mc];
int top;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == mc - 1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow!");
        return;
    }
    s_arr[++top] = val;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
}

void display(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    for(int i=top; i>=0; i--){
        printf("%d\t",s_arr[i]);
    }
    printf("\n");
}

int main(){
    top=-1;
    if (isEmpty()){
        printf("\nStack is empty.\n");
    }
    if (isFull()){
        printf("\nStack is full.\n");
    }

    push(10);

    if (isEmpty()){
        printf("\nStack is empty.\n");
    }
    if (isFull()){
        printf("\nStack is full.\n");
    }

    push(20);
    push(30);

    display();

    pop();

    display();
}