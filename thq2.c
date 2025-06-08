#include <stdio.h>
#define ms 100

int stack[ms];
int top = -1;

void push(int value) {
    if (top == ms - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    int dl, rm;

    printf("Enter a decimal number: ");
    scanf("%d", &dl);

    if (dl == 0) {
        printf("Binary: 0\n");
        return 0;
    }


    while (dl > 0) {
        rm = dl % 2;
        push(rm);
        dl = dl / 2;
    }


    printf("Binary: ");
    while (top != -1) {
        printf("%d", pop());
    }

    printf("\n");

    return 0;
}
