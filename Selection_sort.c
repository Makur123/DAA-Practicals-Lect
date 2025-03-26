#include <stdio.h>

void selection_sort(int arr[], int n, int index) {
    // Base case: when index reaches the end of the array
    if (index == n - 1) {
        return;
    }

    int min_index = index;

    // Find the index of the smallest element in the remaining array
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    // Swap the found minimum element with the current element
    int temp = arr[min_index];
    arr[min_index] = arr[index];
    arr[index] = temp;

    // Recursive call to sort the rest of the array
    selection_sort(arr, n, index + 1);
}

int main() {
    int arr[] = {60, 30, 4, 100, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n, 0);

    printf("Sorted Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
