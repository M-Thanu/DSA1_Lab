#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL, *temp, *new;

void display(){
    if(head==NULL){
        printf("\nList is Empty");
    }
    temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("Back to Head");
    
}

void addAtBegin(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        head=new;
        head->next=head;
        return;
    }
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new;
    new->next=head;
    head=new;

    display();
    
}

void addAtEnd(int val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        head=new;
        head->next=head;
        return;
    }
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new;
    new->next=head;

    display();
}

void addAtPos(int val, int pos){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL || pos<0){
        printf("\nInvalid");
        return;
    }
    if(pos==1){
        addAtBegin(val);
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=head; i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

    display();

}

void delFirst(){
    if(head == NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    temp=head;
    head=head->next;
    free(temp);

    display();

}

void delEnd(){
    if(head == NULL){
        printf("\nList is Empty");
        return;
    }
    temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    struct node*del=temp->next;
    temp->next=head;
    free(del);

    display();
}

void delAtPos(int pos){
    if(head==NULL || pos<0){
        printf("\nInvalid");
        return;
    }
    if(pos==1){
        delFirst();
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=head; i++){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next=del->next;
    free(del);

    display();
}

void search(int key){
    if(head==NULL){
        printf("\nEmpty List");
        return;
    }
    temp=head;
    int pos=1;
    do{
        if(temp->data == key){
            printf("%d found at position %d",key,pos);
            return;
        }
        pos++;
        temp=temp->next;
    }while(temp!=head);
    printf("\n%d not in the list",key);
}

void reverse(){

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
                delAtPos(position);
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