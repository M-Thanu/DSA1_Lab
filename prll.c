#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    
};

struct node* head=NULL, *temp, *new;

void display(){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("head");
}

void addBegin(int value){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    if(head==NULL){
        new->next=new;
        head=new;
        display();
        return;
    }
    
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    new->next=head;
    temp->next=new;
    
    head=new;
    display();
}

void addEnd(int value){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    if(head==NULL){
        new->next=head;
        head=new;
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

void addPos(int value, int pos){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;

    if(pos==1){
        addBegin(value);
    }
    temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    
    display();
}

void delBegin(){
    if(head==NULL){
        printf("Empty List");
        return;
    }

    if(head->next==head){
        free(head);
        head==NULL;
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
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    while(temp->next->next != head){
        temp=temp->next;
    }
    struct node*del=temp->next;
    temp->next=head;
    free(del);
    display();
}

void delPos(int pos){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    if(pos==1){
        delBegin();
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    struct node* del=temp->next;
    temp->next=del->next;
    
    free(del);
    display();
}

void search(int key){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    temp=head;
    int pos=1;
    do{
        if(key==temp->data){
            printf("%d found at %d", key,pos);
            return;
        }
        pos++;
        temp=temp->next;
    }while(temp!=head);
    printf("\nNo such element");
}

void reverse(){
    struct node*curr=head;
    struct node*prev=NULL;
    struct node*next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    display();
}

int main(){
    int d,choice,p;
    while(1){
        printf("\nMenu\n");
        printf("1.AddBegin\n2.AddEnd\n3.AddPos\n4.DelBegin\n5.DelEnd\n6.DelPos\n7.Search\n8.Reverse\n9.Display\n10.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("enter data: ");
                scanf("%d",&d);
                addBegin(d);
                break;
            case 2:
                printf("enter data: ");
                scanf("%d",&d);
                addEnd(d);
                break;
            case 3:
                printf("enter data: ");
                scanf("%d",&d);
                printf("enter position: ");
                scanf("%d",&p);
                addPos(d,p);
                break;
            case 4:
                delBegin();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("enter position: ");
                scanf("%d",&p);
                delPos(p);
                break;
            case 7:
                printf("enter data to search: ");
                scanf("%d",&d);
                search(d);
                break;
            case 8:
                reverse();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Wrong CHoice");
        }
    }
    

    
}