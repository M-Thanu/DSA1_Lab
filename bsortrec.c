#include <stdio.h>

void recursiveBSort(int array[], int n){
    int t;
    if(n==1){
        return ;
    }
    for(int a=0; a<n-1; a++){
        if(array[a] > array[a+1]){
            t=array[a];
            array[a] = array[a+1];
            array[a+1]=t;
        }
    }
    recursiveBSort(array, n-1);
}

int main(){
    int arr[]={5, 2, 9, 1, 5, 6};
    int length= sizeof(arr) / sizeof(arr[0]);

    recursiveBSort(arr, length);

    printf("Sorted Array= ");
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }

    return 0;

}