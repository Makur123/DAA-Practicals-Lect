#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr; 
    int i, j, temp;

    printf("Enter the number of integers\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }
    printf("Enter integers\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j]; 
                arr[j] = temp;       
            }
        }
    }

    printf("sorted integers\n");
    for (i = 0; i < n; i++) { 
        printf("%d\t", arr[i]);
    }
    printf("\n"); 

   
    free(arr);

    return 0; 
}