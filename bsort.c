#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nSorted Marks:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter count: ");
    scanf("%d", &size);

    int marks[size];

    for(int i = 0; i < size; i++) {
        printf("Mark %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    bubbleSort(marks, size);
    float avg;
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += marks[i];
    }
    avg= (float)sum / size;
    printf("Average Mark: %.2f\n", avg);

    printf("Marks greater than average:\n");
    for(int i = 0; i < size; i++) {
        if(marks[i] > avg) {
            printf("%d ", marks[i]);
        }
    }

    return 0;
}
