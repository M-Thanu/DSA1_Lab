#include <stdio.h>

int sample(int n){
    if(n<=1){
        return n;
    }else{
        int a=sample(n-1);
        int b=sample(n-2);
        if(a>b){
            return (a-b);
        }else{
            return (b-a);
        }
    }
}

int main(){
    printf("So %d",sample(5));
    return 0;
}