#include <stdio.h>

int main() {
    int i;

    printf("Modified numbers from 1 to 10:\n");
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("%d ", i - 1);  
        } else {
            printf("%d ", i + 1);  
        }
    }

    return 0;
}
