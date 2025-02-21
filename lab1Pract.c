#include <stdio.h>
int FindMax(int arr1[], int s1);
int FindMin(int arr2[], int s2);

int main(){
    /*
    int arr[6];

    for(int i=0; i<5; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    for(int j=0; j<5; j++){
        printf("%d\t",arr[j]);
    }
    

    int my_arr[10]= {34,56,78,15,43,71,89,34,70,81};
    int max,min;
    max=FindMax(my_arr,10);
    min=FindMin(my_arr,10);
    printf("Highest value element: %d\n",max);
    printf("Lowest value element: %d\n",min);

    

    int arr[]={10,14, 20, 34, 45, 8, 4, 3, 23};
    for (int i=8; i>=0; i--){
        printf("%d\t",arr[i]);
    }
    
    

    int arr[]={10,14, 20,20,8,4, 34, 45, 8, 4, 3, 23,4};
    for (int i=0;i<12; i++){
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                printf("%d appears more\n",arr[j]);
            }
        }
        
    }
    

    int marr[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("Enter: ");
            scanf("%d",&marr[i][j]);
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            
            printf("%d\t",marr[i][j]);
        }
        printf("\n");
    }
    
    int rsum =0;
    int csum=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            rsum=rsum+marr[i][j];
        }
        printf("Row Total: %d\t",rsum);
        rsum=0;
    }
    printf("\n");
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            csum=csum+marr[j][i];
        }
        printf("Coloumn Total: %d\t",csum);
        csum=0;
    }

   int n1;
   int n2;
   int* p1;
   int *p2;
   p1=&n1;
   p2=&n2;

   printf("First: ");
   scanf("%d",p1);

   printf("Second: ");
   scanf("%d",p2);

   printf("Total : %d", *p1+*p2); */



    return 0;
}


int FindMax(int arr1[], int s1){
    int max=0;
    for (int i=0; i<s1; i++){
        if(arr1[i]>max){
            max=arr1[i];
        }
    }
    return max;
}

int FindMin(int arr2[], int s2){
    int min=1000;
    for (int i=0; i<s2; i++){
        if(arr2[i]<min){
            min=arr2[i];
        }
    }
    return min;
}
