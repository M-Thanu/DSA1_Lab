#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL, *temp, *new;

void display(){
    if(head==NULL){
        printf("Empty List");
    }
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void addFirst(int value){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    new->next=temp;
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
    display();
}

void addPos(int pos, int val){
    if(pos<0){
        printf("Invalid Position");
        return;
    }
    if(head==NULL){
        printf("Empty List");
        return;
    }
    new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=NULL ; i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    display();
}

void delFirst(){
    if(head==NULL){
        printf("Empty List");
    }
    temp=head;
    head=head->next;
    free(temp);
}

void delEnd(){
    if(head==NULL){
        printf("Empty List");
    }
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node*del=temp->next;
    temp->next=NULL;
    free(del);
}

void DelPos(int pos){
    if(pos<0){
        printf("Invalid Position");
        return;
    }
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=NULL ; i++){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next=del->next;
    free(del);  
}

void search(int key){
    if(head==NULL){
        printf("Empty List");
    }
    temp=head;
    int pos=1;
    while(temp->next!=NULL){
        if(temp->data==key){
            printf("%d found at position %d",key,pos);
            return;
        }
        pos++;
        temp=temp->next;
    }
    printf("%d is not in the list",key);
}

void reverse(){
    if(head==NULL){
        printf("Empty List");
    }
    struct node *t1=NULL,*t2=NULL;
    
    temp=head;
    while(temp!=NULL){
        t2=temp->next;
        temp->next=t1;
        t1=temp;
        temp=t2;
    }
    head=t1;
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
                addFirst(value);
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
                delFirst();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("\nEnter position: ");
                scanf("%d",&position);
                DelPos(position);
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
