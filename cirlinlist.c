#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

int main(){
    int n;
    printf("Enter the number of nodes: ");
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
    temp->link=head;

    temp=head;
    do{
        printf("%d\t",temp->data);
        temp=temp->link;
    }while(temp != head);

    //Question 02. (i)
    struct node* newn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter new data: ");
    scanf("%d",&newn->data);
    newn->link=head;
    temp=head;
    while(temp->link != head){
        temp = temp->link;
    }
    temp->link = newn;

    temp=head;
    do{
        printf("%d\t",temp->data);
        temp=temp->link;
    }while(temp != head);

    //Question 02 (ii)
    printf("\n");
    head=head->link;
    temp=head;
    do{
        printf("%d\t",temp->data);
        temp=temp->link;
    }while(temp != head);

}