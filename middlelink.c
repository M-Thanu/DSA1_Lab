#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL, *temp=NULL, *new;

void add(int value){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
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

int count(){
    int c=0;
    if(head==NULL){
        return 0;
    }
    temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

void position(int p){
    if(p<0){
        return;
    }
    if(head==NULL){
        return ;
    }
    temp=head;
    for(int i=1; i<p && temp->next!=NULL; i++ ){
        temp=temp->next;
    }
    printf("\nMiddle Element: %d",temp->data);
}


int main(){
    int ch,val,l,pos;
    while(1){
        printf("Adding Node(0) or Ending(1): ");
        scanf("%d",&ch);
        if(ch==0){
            printf("\nEnter the data: ");
            scanf("%d",&val);
            add(val);
        }else{
            l=count();
            if(l % 2 != 0){
                pos=(l/2)+1;
                position(pos);
            }else{
                pos=l/2;
                position(pos);
                position(pos+1);
            }
            
            exit(0);
        }
    }
    return 0;
}