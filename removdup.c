#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    struct node *head=NULL, *temp, *new;

    for(int i=0; i<n; i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data %d: ",i+1);
        scanf("%d",&new->data);
        new->link=NULL;

        if(head==NULL){
            head=new;
            temp = head;
        }else{
            temp->link=new;
            temp=new;
        }

    }
    //printing list
    printf("\nBefore: ");
    temp=head;
    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }

    struct node* c1;
    c1=head;
    
    while(c1->link!=NULL){
        struct node *c2;
        c2=c1;
        while(c2->link!=NULL){
            if(c1->data==c2->link->data){
                c2->link=c2->link->link;
            }
            else{
                c2=c2->link;
            }

        }
        c1=c1->link;
    }

    printf("\nAfter: ");
    temp=head;
    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}