#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char* data;
    struct node* prev;
    struct node* next;
};

struct node *head=NULL, *temp, *new;

void addSong(char *val){
    new=(struct node*)malloc(sizeof(struct node));
    new->data = (char*)malloc(strlen(val) + 1); 
    strcpy(new->data , val);
    new->prev=NULL;
    new->next=NULL;
    if(head==NULL){
        head=new;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new->prev=temp;
    temp->next=new;
    
}

void display(){
    printf("\nSongs in Your Playlist are : \n");
    if(head==NULL){
        printf("Empty Playlist");
    }
    temp=head;
    while(temp!=NULL){
        printf("%s\t",temp->data);
        temp=temp->next;
    }
    printf("Finished\n");

}

void delSong(int pos){
    if(pos<0){
        printf("\nInvalid Position");
    }
    if(head==NULL){
        printf("\nEmpty Playlist");
    }
    if(pos==1){
        temp=head;
        head->next->prev=NULL;
        head=head->next;
        free(temp);
    }
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=NULL; i++){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next=del->next;
    del->next->prev=temp;
    free(del);
    display();
}

void nextSong(int pos){
    if(pos<0){
        printf("\nInvalid Position");
    }
    if(head==NULL){
        printf("\nEmpty Playlist");
    }
    temp=head;
    for(int i=1; i<pos && temp->next!=NULL; i++){
        temp=temp->next;
    }
    if(temp->next != NULL){
        printf("\nThe next song is %s",temp->next->data);
    }else{
        printf("\nEnd of Playlist");
    }  

}

void prevSong(int pos){
    if(pos<0){
        printf("\nInvalid Position");
    }
    if(head==NULL){
        printf("\nEmpty Playlist");
    }
    temp=head;
    for(int i=1; i<pos && temp->next!=NULL; i++){
        temp=temp->next;
    }
    if(temp->prev != NULL){
        printf("\nThe previous song is %s",temp->prev->data);
    }else{
        printf("\nThat was the first song");
    }  

}

int main(){
    while(1){
        printf("\nMusic Player Menu:\n");
        printf("1.Add new song\n2.Display Playlist\n3.Delete a song\n4.Previous Song\n5.Next Song\n6.Exit\n");
        int ch;
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        int position;
        char value[100];

    
        switch(ch){
            case 1:
                printf("\nEnter song: ");
                scanf("%s",&value);
                addSong(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter position: ");
                scanf("%d",&position);
                delSong(position);
                break;
            case 4:
                printf("\nEnter number of current song: ");
                scanf("%d",&position);
                prevSong(position);
                break;
            case 5:
                printf("\nEnter number of current song: ");
                scanf("%d",&position);
                nextSong(position);
                break;
            case 6:
                exit(0);
            default:
                printf("wrong choice\n");
    
        }
    }
    return 0;     
}
