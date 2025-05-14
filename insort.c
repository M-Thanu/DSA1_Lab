#include <stdio.h>

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }
}

void insertionSort(int arr[], int size){
    int temp,j;
    for(int i=1; i<size; i++){
        temp=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int main(){
    int a[]={5,4,10,1,6,2};
    int j, temp;
    int n= sizeof(a)/sizeof(a[0]);

    printf("Array:\n");
    printArr(a,n);

    insertionSort(a,n);

    printf("\nArray after Insertion Sort:\n");
    printArr(a,n);
    

}