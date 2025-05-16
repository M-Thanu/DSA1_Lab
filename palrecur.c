#include <stdio.h>
#include <string.h>

int checkPalindrome(char str[], int first, int last){
    if(first >= last){
        return 1;
    }
    if (str[first] != str[last]){
        return 0;
    }
    return checkPalindrome(str, first+1, last-1);
}

int main(){
    char word[30];

    printf("Input a word to check for palindrome: ");
    scanf("%s", word);

    int length = strlen(word);

    if(checkPalindrome(word, 0,length-1)){
        printf("The string is a palindrome");
    }else{
        printf("The string is not a palimdrome");
    }

    return 0;
}