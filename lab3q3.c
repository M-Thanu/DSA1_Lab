#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=NULL;

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&new->data);
        new->next=NULL;
        new->prev=NULL;

        if(head==NULL){
            head=new;
            temp=head;
        }else{
            new->prev=temp;
            temp->next=new;
            temp=new;
        }    
    }

    int k=0;
    temp=head;
    printf("\nData in forward order are: \n");
    while(temp!=NULL){
        printf("Data in node %d : %d\n",k+1,temp->data);

        if(temp->next == NULL){
            break;
        }
        temp=temp->next;
        k++;
    }
    k=0;
    printf("\nData in backward order are: \n");
    while(temp != NULL){
        printf("Data in node %d : %d\n",k+1,temp->data);
        temp=temp->prev;
        k++;
    }

    //Finding min and max
    int min=100;
    int max=0;

    temp=head;
    while(temp!=NULL){
        if(temp->data < min){
            min=temp->data;
        }
        if(temp->data > max){
            max=temp->data;
        }
        temp=temp->next;
    }
    printf("\nMax: %d",max);
    printf("\nMin: %d",min);

}
