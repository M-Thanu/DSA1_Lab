#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL, *new, *temp;

void display(){
    if(top==NULL){
        printf("Empty List");
        return ;
    }
    temp=top;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("Finish\n");
}

int isEmpty(){
    return top==NULL;
}

void push(int value){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=top;
    top=new;
}

void pop(){
    temp=top;
    top=top->next;
    free(temp);
    display();
}

void peek(){
    if(top==NULL){
        printf("Empty List");
        return ;
    }
    printf("Top Element: %d",top->data);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Operations (Linked List) ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");
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
            display();
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}