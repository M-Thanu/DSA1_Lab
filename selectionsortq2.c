#include <stdio.h>

 //Performing Insertion Sort
void insertionSortAsc(int a[], int n){
    int temp;
        for(int i=1; i<n; i++){
            temp=a[i];
            int j=i-1;
            while(j>=0 && a[j]>temp){
                a[j+1] = a[j];
                j--;
            }
            a[j+1]=temp;
        }

        for(int i=0; i<n; i++){
            printf("%d\t",a[i]);
        }
}

//Performing Selection sort in ascending order
void selectionSortAsc(int a[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int min=i;
        for (int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min != i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
}

//Selection Sort Descending Order
void selectionSortDsc(int a[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int max=i;
        for (int j=i+1; j<n; j++){
            if(a[j]>a[max]){
                max=j;
            }
        }
        if(max != i){
            temp=a[i];
            a[i]=a[max];
            a[max]=temp;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    int num;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int arr[num];
    int temp,i,j=0;
    
    //Getting elements as input
    for(int i=0; i<num; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&temp);
        arr[i]=temp;
    }

    printf("Insertion Sort: \n");
    selectionSortAsc(arr, num);
    printf("\nSelection Sort Ascending : \n");
    selectionSortAsc(arr, num);
    printf("\nSelection Sort Descending : \n");
    selectionSortDsc(arr, num);

    return 0;
}