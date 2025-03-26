#include <stdio.h>
#define INT_MAX 1000

void RankIndex(int arr[], int n) {
    int Rank[n], rank = 1, k, min;

    // Initialize the Rank array to 0 (not ranked)
    for (int i = 0; i < n; i++) {
        Rank[i] = 0;
    }

    // Loop to assign ranks to each element
    for (int i = 0; i < n; i++) {
        // Find the first unranked element
        for (k = 0; Rank[k] != 0; k++);
        min = k;

        // Find the smallest unranked element
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[min] && Rank[j] == 0) {
                min = j;
            }
        }

        // Assign the rank to the smallest element
        Rank[min] = rank;

        // Increment the rank for the next smallest element
        rank++;
    }

    // Print the elements and their ranks
    printf("Element\tRank\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", arr[i], Rank[i]);
    }
}

int main() {
    int arr[] = {50, 30, 90, 80, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the RankIndex function
    RankIndex(arr, n);

    return 0;
}
