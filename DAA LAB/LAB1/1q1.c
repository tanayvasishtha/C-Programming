/*1.1 Aim of the program: Write a program to find out the second smallest and second largest
element stored in an array of n integers.*/

#include <stdio.h>
#include <limits.h>

void findSecondSmallestLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    if (n < 2) {
        *secondSmallest = *secondLargest = INT_MIN;
        return;
    }

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = &smallest;
            smallest = arr[i];
        } else if (arr[i] < *secondSmallest && arr[i] != smallest) {
            *secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            secondLargest = &largest;
            largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != largest) {
            *secondLargest = arr[i];
        }
    }
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int secondSmallest, secondLargest;
    findSecondSmallestLargest(arr, n, &secondSmallest, &secondLargest);

    printf("Second smallest: %d\n", secondSmallest);
    printf("Second largest: %d\n", secondLargest);

    return 0;
}
