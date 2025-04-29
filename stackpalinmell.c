#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node* next;
};

struct node* top=NULL, *new, *temp;

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
    char rd;
    rd=top->data;
    top=top->next;
    return rd;
}

int main(){
    printf("Palindrome Checker");
    char word[100];

    printf("\nEnter Word: ");
    scanf("%s",word);
    int i=0;

    while(word[i]!='\0'){
        push(word[i]);
        i++;
    }

    char rword[100];
    int j=0;

    while(1){
        rword[j]=pop();
        j++;
        if(isEmpty()){
            break;
        }
    }
    rword[j]='\0';
    if(strcmp(word,rword)==0){
        printf("Palindrome");
    }else{
        printf("Not a Palindrome");
    }

}

