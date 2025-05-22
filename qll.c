#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*rear=NULL;
struct node*front=NULL;

int isEmpty(){
    return front==NULL;
}

void enqueue(int val){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;

    if(rear == NULL){
        rear=front=new;
    }else{
        rear->next=new;
        rear=new;
    }
    
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
}

void peek(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }else{
        printf("Top: %d",front->data);
    }
}

void display(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }
    struct node* temp=front;
    while(temp != NULL){
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
                enqueue(d);
                break;
            case 2:
                dequeue();
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