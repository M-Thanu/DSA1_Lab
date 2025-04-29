#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
};

struct node*top=NULL, *temp, *new;

int isEmpty(){
    return top==NULL;
}

void push(char val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=top;
    top=new;
}

char pop(){
    char s;
    s=top->data;
    top=top->next;
    return s;
}

char peek(){
    return top;
}

int isMatching(char a, char b){
    if((a=='{'&& b =='}')||(a=='['&& b ==']')||(a=='('&& b ==')')){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char word[100];
    printf("Enter: ");
    scanf("%s",word);
    char pd;
    int r;

    for(int i=0; word[i]!='\0'; i++){
        if(word[i]=='{'|| word[i]=='['|| word[i]=='('){
            push(word[i]);
        }else if(word[i]=='}'|| word[i]==']'|| word[i]==')'){
            pd=pop();
            r=isMatching(pd,word[i]);
            if(!r){
                printf("Invalid");
                return 0;
            }
        }
    }
    printf("Match");
}