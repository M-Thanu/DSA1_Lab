#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=10;
    head->next=NULL;

    struct node* n2=(struct node*)malloc(sizeof(struct node));
    n2->prev=head;
    n2->data=20;
    n2->next=NULL;
    head->next=n2;

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    return 0;

}