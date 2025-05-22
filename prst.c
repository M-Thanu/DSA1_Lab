#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *top=NULL;

int isEmpty(){
    return (top==NULL);
}

void push(value){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=top;
    top=new;
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        return;
    }
    top=top->next;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        return 1;
    }
    printf("Top: %d",top->data);
}

void display(){
     if(isEmpty()){
        printf("Stack Underflow");
        return ;
    }
    struct node* temp=top;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }      
}

int main(){
    int d,choice,p;
    while(1){
        printf("\nMenu\n");
        printf("1.Add\n2.Delete\n3.Peek\n4.Full\n5.Empty\n6.Display\n7.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("enter data: ");
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 5:
                if(isEmpty()){
                    printf("Stack underflow");
                }else{
                    printf("Add");
                }
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong CHoice");
        }
    }
}