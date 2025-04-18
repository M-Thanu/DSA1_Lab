#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node* next;
};

struct node* top=NULL;
int count=0;

void push(char value){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=top;
    top=new;
}

int isEmpty(){
    return top == NULL;
}

char pop(){
    if(isEmpty()){
        return '\0';
    }
    char popped=top->data;
    top=top->next;
    return popped;
}

/*int isMatch(char open, char close){
    return((open == '(' && close == ')') || 
           (open == '[' && close == ']') ||
           (open == '{' && close == '}'));
}*/

int isBalance(char* w){
    for(int i=0; w[i]!='\0'; i++){
        char c=w[i];

        if(c!='>' || c!='/'){
            push(c);
        } else if(c=='>'){
            if(isEmpty()){
                printf("\nStack is Empty");
                return 0;
            }
            push(c);
        } else if(c=='>' && c!='<'){
            do{
                push(c);
                count++;
            }while(c=='<');
        } else if(c=='/'){
            for(int i=0; i<count+1; i++){
                pop();
            }
            count=0;
            char c1,c2;
            c1=pop();
            c2=pop();
            if(c1==w[i+1] && c2==w[i+2] ){
                return 0;
            }
        }
    }
    return isEmpty();
}

int main(){
    char word[100];
    printf("Enter Tags: ");
    scanf("%s",word);

    if(isBalance(word)){
        printf("Valid");
    }else{
        printf("Invalid");
    }

    return 0;
    
}