#include <stdio.h>

int main(){
    int arr[]={5,4,10,1,6,2};

    int i,j,temp=0;
    int n=6;

    for(i=1; i<n; i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    int k=0;
    while(k<n){
        printf("%d\t",arr[k]);
        k++;
    }
    return 0;
}