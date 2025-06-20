#include <stdio.h>

int main(){
    int arr[]={456,120,653,310,209};
    int n=5;

    int srr[6];
    int t=0;
    int k=0;

    for(int i=0; i<n; i++){
        k=arr[i];
        while(k>=1){
            t=t+(k%10);
            k=k/10;
        }
        srr[i]=t;
        t=0;
    }

        int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(srr[j]>srr[j+1]){
                temp=srr[j];
                srr[j]=srr[j+1];
                srr[j+1]=temp;

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}