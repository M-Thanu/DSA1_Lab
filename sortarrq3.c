#include <stdio.h>

int main(){
    int n;
    
    int temp,i,j=0;
    while(1){
        printf("Enter the number of elements: ");
        scanf("%d",&temp);
        if(temp<=10){
            n=temp;
            break;
        }else{
            printf("Only 10 elements allowed\n");
        }
    }
    int arr[n];
    //Getting elements as input
    for(int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&temp);
        arr[i]=temp;
    }
    

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