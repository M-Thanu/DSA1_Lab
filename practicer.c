#include <stdio.h>

//Printing numbers N to 1
void printNum(int num){
    if(num == 0){
        return;
    }else{
        printf("%d\t",num);
    }
    printNum(num-1);
}

//Sum of first n numbers
int printSum(int num){
    if(num == 0){
        return 0;
    }else{
        return num+printSum(num-1);
    }
}

//Factorial
int factorial(int num){
    if(num==0 || num==1){
        return 1;
    }else{
        return num*factorial(num-1);
    }
}

//Total of array
int arrSum(int arr[], int n){
    if(n==0){
        return 0;
    }else{
        return arr[n-1]+arrSum(arr,n-1);
    }
}

//Fibonacci
int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(){
    int n;
    printf("Enter N: ");
    scanf("%d",&n);

    //int array[]={1,2,3};
    //int a=3;

    for(int i=0; i<n; i++){
        printf("%d",fibonacci(i));
    }
    //int t= arrSum(array,a);
    //printf("\n%d",t);

    return 0;
}