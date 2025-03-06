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


    //struct node* t1;
    temp=head;
    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}