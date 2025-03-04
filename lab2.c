#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* crlist(int a){
    struct node* head = NULL,
    *temp = NULL,
    *newNode;

    for(int i=0; i<a; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode -> link = NULL;
    }

    if (head == NULL){
        head=newNode;
        temp = head;
    }else{
        temp->link = newNode;
        temp = newNode;
    }
}

void displaylist(struct node* head){
    struct node* temp=head;
    printf("List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct node* head= crlist(n);
    displaylist(head);
    return 0;
}