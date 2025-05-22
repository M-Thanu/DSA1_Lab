#include <stdio.h>

void inSort(int arr[], int n);
void selSort(int arr[], int n);
void bsort(int arr[], int n);

int main(){
    int array[]={5, 2, 10, 8, 3};
    int l=sizeof(array)/sizeof(array[0]);

    bSort(array, l);

    for(int i=0; i<l; i++){
        printf("%d\t",array[i]);
    }

    return 0;
}

void inSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void selSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        int j=i+1;
        while(j<n && arr[min]>arr[j]){
            min=j;
            j++;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void bSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}