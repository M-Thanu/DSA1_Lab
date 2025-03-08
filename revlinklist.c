#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

int main(){
    int n;
    printf("Enter the node count: ");
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

    printf("\nBefore: ");
    temp=head;
    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }

    printf("\nAfter: ");

    struct node* temp2=NULL;

    while(head!=NULL){
        temp2=head->link;
        head->link=temp;
        temp=head;
        head=temp2;
    }
    head=temp;

    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}