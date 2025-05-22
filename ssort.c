#include <stdio.h>

void SelectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        int j=i+1;
        while(j<n){
            if(arr[j]<arr[min]){
                min=j;
            }
            j++;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main(){
    int array[]={7,5,8,2,9};
    int l=sizeof(array)/sizeof(array[0]);

    SelectionSort(array, l);

    for(int i=0; i<l; i++){
        printf("%d\t",array[i]);
    }
    return 0;
}