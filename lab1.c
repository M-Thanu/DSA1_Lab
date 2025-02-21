#include <stdio.h>

int main(){
    int arr1[]={10, 14, 20, 34, 45, 8, 4, 3, 23};

    int size=9;
    
    for(int j=0; j<9; j++){
        printf("%d\t",arr1[j]);
    }
    printf("\n");
    for(int i=size-1; i<2; i--){
       arr1[i+1] = arr1[i];
    }
    arr1[2]=12;

    for(int j=0; j<10; j++){
        printf("%d\t",arr1[j]);
    }

    printf("\n------------------------------------------------------------------------------------------------\n");

    int arr2[]={10, 14, 20, 34, 45, 8, 4, 3, 23};

    
    for(int j=0; j<9; j++){
        printf("%d\t",arr2[j]);
    }
    printf("\n");
    for(int i=5; i<8; i++){
       arr2[i] = arr2[i+1];
    }
    

    for(int j=0; j<8; j++){
        printf("%d\t",arr2[j]);
    }
    
}