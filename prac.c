#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*n2;
    n2=(struct node*)malloc(sizeof(struct node));
    n2->data=98;
    n2->link=NULL;
    head->link=n2;

    struct node*n3;
    n3=(struct node*)malloc(sizeof(struct node));
    n3->data=3;
    n3->link=NULL;
    n2->link=n3;
    
    struct node* temp;
    temp=head;
    for(int i=0; i<3; i++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}