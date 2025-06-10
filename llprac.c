#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head, *temp, *new=NULL;

void addBegin(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;

    if(head==NULL){
        head=new;
        return;
    }
    new->next=head;
    head=new;
}

void addEnd(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}

void addPos(int val, int pos){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    for(int i=1; i<pos; i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
}

void delbegin(){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    head=head->next;
    free(temp);
}

void delend(){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node* del=temp->next;
    temp->next=NULL;
    free(del);
}

void delPos(int pos){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next=del->next;
    free(del);
}

void search(int key){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    int c=1;
    temp=head;
    while(temp!=NULL){
        if(key==temp->data){
            printf("%d found at %d",key,c);
            return ;
        }
        temp=temp->next;
        c++;
    }
}

void display(){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

void reverse(){
    struct node *prev=NULL, *ag=NULL;
    temp=head;
    while(temp!=NULL){
        ag=temp->next;
        temp->next=prev;
        prev=temp;
        temp=ag;
    }
    head=prev;
    display();
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
                addBegin(value);
                break;
            case 2:
                printf("\nEnter value: ");
                scanf("%d",&value);
                addEnd(value);
                break;
            case 3:
                printf("\nEnter value: ");
                scanf("%d",&value);
                printf("\nEnter position: ");
                scanf("%d",&position);
                addPos(value,position);
                break;
            case 4:
                delbegin();
                break;
            case 5:
                delend();
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