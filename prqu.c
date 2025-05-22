#include <stdio.h>

#define MAX 100
int queue[MAX];

int rear=-1;
int front=-1;

int isFull(){
    return (rear==MAX-1);
}

int isEmpty(){
    return(front==-1 || front>rear);
}

void enqueue(int value){
    if(isEmpty()){
        front++;
    }
    rear++;
    queue[rear]=value;
}

void dequeue(){
    if(isEmpty()){
        printf("Nothing");
        return ; 
    }
    front++;
    if(front>rear){
        front=rear=-1;
    }
}

void peek(){
   if(isEmpty()){
        printf("Nothing");
        return ; 
    }
    printf("TOp: %d",queue[front]);
}

void display(){
    if(isEmpty()){
        printf("Nothing");
        return ; 
    }
    for(int i=front; i<=rear; i++){
        printf("%d\t",queue[i]);
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