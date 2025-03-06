#include <stdio.h>
#include <stdlib.h>

//Creating the Structure
struct node{
    int data;
    struct node* link;
};

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    //Creating a linked list of n numbers
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

    //Printing the linked list
    temp=head;
    for(int j=0; j<n; j++){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    
    //----------------------------
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    int d;
    printf("Enter data: ");
    scanf("%d",&d);
    
    //Creating seperate location for new data
    struct node* ptr, *h;
    ptr = (struct node*)malloc(sizeof(struct node ));
    ptr->data = d;
    ptr->link = NULL;
    temp = head;
    
    
    while((pos-1)!=1){
        temp=temp->link;
        pos--;
    }
    
    ptr->link=temp->link;
    temp->link=ptr;
    
    temp=head;
    while(temp !=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    
}