#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*link;
} *top=NULL,*temp=NULL;

void push(int a);
void pop();
void print();

void listcr(){
    int val;
    for(int i=0; i<3; i++){
        printf("ENter data for creation : ");
        scanf("%d",&val);
        push(val);
    }
    
}

void choice(){
    int ch;
    int d;
    while(1){
        printf("Choices\n");
        printf("1.Push\n2.Pop\n3.Print all elements of stack\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter data to be pushed: ");
                scanf("%d",&d);
                push(d);
                break;
            
            case 2:
                pop();
                break;

            case 3:
                print();
                break;
            
            case 4:
                exit(0);
            
            default:
                printf("Not a valid choice");
        }
    }
    
}

int main(){

    listcr();
    choice();
    
    
    return 0;
}

void push(int a){
    struct node*nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=a;
    nnode->link=NULL;
    nnode->link=top;
    top=nnode;
}

void pop(){
    top=top->link;
}

void print(){
    temp=top;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}