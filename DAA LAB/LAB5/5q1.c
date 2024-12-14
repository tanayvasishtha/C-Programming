/*Aim of the program: Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.
Input:

Enter the number of items: 3
Enter the profit and weight of item no 1: 27 16
Enter the profit and weight of item no 2: 14 12
Enter the profit and weight of item no 3: 26 13
Enter the capacity of knapsack:18

Output:

Item No profit Weight Amount to be taken
3 26.000000 13.000000 1.000000
1 27.000000 16.000000 0.312500
2 14.000000 12.000000 0.000000
Maximum profit: 34.437500*/
#include <stdio.h>
#include <stdlib.h>

struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void heapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(struct ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

float fractionalKnapsack(struct ITEM items[], int n, float capacity) {
    heapSort(items, n);

    float maxProfit = 0.0;
    float currentWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].item_weight <= capacity) {
            currentWeight += items[i].item_weight;
            maxProfit += items[i].item_profit;
            items[i].profit_weight_ratio = 1.0;
        } else {
            float remainingWeight = capacity - currentWeight;
            float fraction = remainingWeight / items[i].item_weight;
            currentWeight += remainingWeight;
            maxProfit += items[i].item_profit * fraction;
            items[i].profit_weight_ratio = fraction;
            break;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM *items = (struct ITEM *)malloc(n * sizeof(struct ITEM));

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    float capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].profit_weight_ratio);
    }

    printf("Maximum profit: %.6f\n", maxProfit);

    free(items);

    return 0;
}





