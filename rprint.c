#include <stdio.h>
#include <string.h>

void revword(char *w, int n){
    if(n<0){
        return ;
    }else{
        printf("%c ",w[n]);
        revword(w,n-1);
        
    }
}
int main(){
    char word[100];
    printf("Enter word: ");
    scanf("%s",word);
    int len;
    len=strlen(word);
    revword(word, len-1);

    return 0;
}


/*
Print numbers from 1 to N using recursion

Print numbers from N to 1 using recursion

Find factorial of a number

Print the sum of first N natural numbers

Check if a number is prime using recursion

Print Fibonacci series up to N terms

Find the power of a number (a^b) using recursion

Reverse a string using recursion

Check if a string is a palindrome using recursion

Find the sum of digits of a number using recursion
*/