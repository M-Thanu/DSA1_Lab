#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=NULL;

    //Question 01.(a)
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);
        new->next=NULL;
        new->prev=NULL;

        if(head==NULL){
            head=new;
            temp=head;
        }else{
            new->prev=temp;
            temp->next=new;
            temp=new;
        }
    }
    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");

    //Question 01. (i)
    struct node* newn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newn->data);
    newn->next=NULL;
    newn->prev=NULL;
    temp=head;

    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newn;
    newn->prev=temp;

    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");

    //Take Home Question 01
    struct node* hn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&hn->data);
    hn->next=NULL;
    hn->prev=NULL;
    temp=head;
    head=hn;
    head->next=temp;

    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");

    //Question 01. (ii)
    head=head->next;
    printf("\n");
    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");

    //Question 01. (iii)
    struct node* temp2;
    temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;

    printf("\n");
    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");


    return 0;

}