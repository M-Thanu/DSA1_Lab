#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*front, *rear;

void enqueue(int num){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=num;
    n->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=n;
    }else{
        rear->next=n;
        rear=n;
    }
}

void dequeue(){
    struct node* t;
    t=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    free(t);
}

void peek(){
    printf("%d",front->data);
}

void display(){
    struct node* t;
    t=front;
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->next;
    }
}

void isEmpty(){
    if(front==NULL){
        printf("Queue is empty");
    }else{
        printf("Queue is not empty");
    }

}
void isFull(){
    printf("Not Defined as total memory space is not assigned");

}

int main(){

   
    while(1){
        printf("\n");
        int ch;
        printf("Menu\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.isFull\n6.Display\n7.Exit");
        printf("\nENter the choice: ");
        scanf("%d",&ch);
        int d;
        switch(ch){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&d);
                enqueue(d);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Enter correct choice");
        }
    }
    
   
    return 0;
}