#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float weight;
    float value;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

float greedyKnapsack(Item items[], int n, float W) {
    
    qsort(items, n, sizeof(Item), compare);

    float currentWeight = 0.0, maxValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        } else {
           
            float remainingWeight = W - currentWeight;
            maxValue += items[i].value * (remainingWeight / items[i].weight);
            break; 
        }
    }

    return maxValue;
}

int main() {
    int n;
    float W;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%f", &W);

    
    Item items[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (Weight Value): ", i + 1);
        scanf("%f %f", &items[i].weight, &items[i].value);
        items[i].ratio = items[i].value / items[i].weight; // Calculate ratio
    }

    float maxValue = greedyKnapsack(items, n, W);
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    return 0;
}