#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL, *new, *temp;

int isEmpty(){
    return top==NULL;
}

void push(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=top;
    top=new;
}

void pop(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    temp=top;
    top=top->next;
    free(temp);
}

void peek(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    printf("Top Element: %d",top->data);
}

void display(){
    if(isEmpty()){
        printf("Empty List");
        return;
    }
    temp=top;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    while(1){
        printf("\nMenu");
        printf("\n1.Add\n2.Delete\n3.Display\n4.Top\n5.Exit");
        int ch,d;
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter: ");
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong Choice");
        }
    }
    
}