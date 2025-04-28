#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int s_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void display(){
    if(isEmpty()){
        printf("Stack UnderFlow");
        return;
    }
    for(int i=top; i>=0; i--){
        printf("%d\t",s_arr[i]);
    }
    printf("\n");
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    s_arr[top]=data;
    printf("Pushed Successfully\n");
    display();
}

int pop(){
    if(isEmpty()){
        printf("Stack UnderFlow");
        exit(1);
    }
    int d;
    d=s_arr[top];
    top=top-1;
    return d;
}

int main(){
    while(1){
        printf("Menu\n");
        printf("1.Add Element\n2.Delete Element\n3.Check if Array is Full\n4.Check if Array is Empty\n5.Top Element\n6.Display Elements\n7.Exit\n");
        int ch,data;
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data to be added: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data=pop();
                printf("%d is deleted\n",data);
                break;
            case 3:
                if(isFull()){
                    printf("Stack Overflow\n");
                }else{
                    printf("Stack is not Full yet\n");
                }
                break;
            case 4:
                if(isEmpty()){
                    printf("Stack Underflow\n");
                }else{
                    printf("Stack is not Empty\n");
                }
                break;
            case 5:
                printf("Top element: %d\n",s_arr[top]);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong Choice");
        }
    }
    return 0;
    
}
