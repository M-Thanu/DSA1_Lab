#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node* next;
};

struct node* head=NULL;

void push(char value){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;

    if(head==NULL){
        head=new;
        return;
    }
    struct node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=new;
}

int isEmpty(){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

char pop(){
    if(head == NULL){
        printf("Empty List");
    }
    struct node* temp=head;
    if(temp->next == NULL){
        char v=temp->data;
        free(temp);
        head=NULL;
        return v;
    }
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    struct node* del=temp->next;
    temp->next=NULL;
    return del->data;
    //free(del);
}

int main(){
    char word[100];
    printf("Enter word: ");
    scanf("%s",word);
    
    for(int i=0; word[i]!='\0'; i++){
        push(word[i]);
    }

    char reply[100];
    char c=0;
    while(!isEmpty()){
        reply[c]=pop();
        c++;
    }
    reply[c]='\0';
    
    if(strcmp(word,reply)==0){
        printf("%s is a palindrome",word);
    }else{
        printf("%s is not a palindrome",word);
    }
   
}

 /*
    
    struct node*temp=head;
    while(temp!=NULL){
        printf("%c\t",temp->data);
        temp=temp->next;
    }
    */