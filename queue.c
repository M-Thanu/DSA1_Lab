#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node*front, *new;
    struct node*temp = NULL;
    front=(struct node*)malloc(sizeof(struct node));

    int num;
    printf("ENter the number of elements: ");
    scanf("%d",&num);
    int d;

    for(int i=0; i<num; i++){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&d);
        new->data=d;
        new->next=NULL;

        if(front==NULL){
            front=new;
            temp=front;
        }else{
            temp->next=temp;
            temp=new;
            
        }
        
    }
    return 0;
}