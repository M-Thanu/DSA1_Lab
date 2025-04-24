#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node *head=NULL, *temp, *new;

void display(){
    if(head==NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void addAtBegin(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->prev=NULL;
    new->next=NULL;

    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    head=new;
    head->next=temp;
    temp->prev=head;
    display();
}

void addAtEnd(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->prev=NULL;
    new->next=NULL;

    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new->prev=temp;
    temp->next=new;
    display();
}

void addAtPos(int val, int pos){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->prev=NULL;
    new->next=NULL;

    if(pos<0){
        printf("\nInvalid Position");
        return;
    }
    if(head==NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    new->prev=temp;
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    display();
}

void delFirst(){
    if(head==NULL){
        printf("\nEMpty");
        return;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    display();
}

void delEnd(){
    if(head==NULL){
        printf("\nEmpty");
        return;
    }
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node *del= temp->next;
    temp->next=NULL;
    free(del);
    display();
}

void delPos(int pos){
    if(pos<0){
        printf("\nInvalid Position");
        return;
    }
    if(head==NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    struct node *del= temp->next;
    del->next->prev=del->prev;
    temp->next=del->next;
    free(del);
    display();
}


void search(int key){
    if(head==NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    int pos=1;
    while(temp->next!=NULL){
        if(key==temp->data){
            printf("\n%d found at position %d",key,pos);
            return ;
        }
        temp=temp->next;
        pos++;
    }
    printf("\n%d not found");
    display();
}

void reverse(){
    if(head==NULL){
        printf("\nList is Empty");
        return;
    }

}

int main(){
    while(1){
        printf("\nMenu:\n");
        printf("1.Add at Beginning\n2.Add at End\n3.Add at Position\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Display\n8.Search\n9.Reverse\n10.exit\n");
        int ch;
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        int value,position;

    
        switch(ch){
            case 1:
                printf("\nEnter value: ");
                scanf("%d",&value);
                addAtBegin(value);
                break;
            case 2:
                printf("\nEnter value: ");
                scanf("%d",&value);
                addAtEnd(value);
                break;
            case 3:
                printf("\nEnter value: ");
                scanf("%d",&value);
                printf("\nEnter position: ");
                scanf("%d",&position);
                addAtPos(value,position);
                break;
            case 4:
                delFirst();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("\nEnter position: ");
                scanf("%d",&position);
                delPos(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\nEnter data to search: ");
                scanf("%d",&position);
                search(position);
                break;
            case 9:
                reverse();
                break;
            case 10:
                exit(0);
            default:
                printf("wrong choice\n");
    
        }
    }
    return 0;     
}
