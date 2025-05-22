#include <stdio.h>

int SUm(int n){
    if(n==0){
        return 0;
    }else{
        return n+SUm(n-1);
        
    }
}

int main(){
    int a;
    printf("Enter: ");
    scanf("%d",&a);

    int r=SUm(a);
    printf("Sum: %d",r);

    return 0;
}