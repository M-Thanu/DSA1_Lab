#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int s_arr[5]={2,8,4,9,12};
int r_arr[5];

struct node*top=NULL, *new, *temp;

void push(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=top;
    top=new;
}

int pop(){
    int d;
    d=top->data;
    top=top->next;
    return d;
}

int isEmpty(){
    return top==NULL;
}

int peek(){
    int a;
    a=top->data;
    return a;
}

int main(){
    for(int i=4; i>=0; i--){
        push(s_arr[i]);
    }
    int popd,peekd;
    int c=0;
    while(!isEmpty()){
        popd=pop();
        peekd=peek();
        if(popd<peekd){
            r_arr[c]=peekd;
        }else{
            int tem,p2;
            while(popd>peekd){
                tem=pop();
                peekd=peek();
            }
            r_arr[c]=peekd;
            push(tem);    
        }
        c++;
    }
    for(int j=0; j<4; j++){
        printf("%d\t",r_arr[j]);
    }
}