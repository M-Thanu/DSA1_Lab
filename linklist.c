#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* head;
    head = (struct node* ) malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node* c1;
    c1 = (struct node* ) malloc(sizeof(struct node));
    c1->data=15;
    c1->link=NULL;
    head->link=c1;

    struct node* c2;
    c2 = (struct node* ) malloc(sizeof(struct node));
    c2->data=5;
    c2->link=NULL;
    c1->link=c2;

    struct node* temp;
    temp=head;

    while(temp != NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }

    free(head);
    free(c1);
    free(c2);
}