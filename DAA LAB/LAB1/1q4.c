/*1.4 Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &amp;
q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.*/

#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    int last = *(p1 + p2 - 1); // Store the last element

    // Shift elements from right to left
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(p1 + i, p1 + i - 1);
    }

    // Place the last element at the beginning
    *p1 = last;
}

#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    ROTATE_RIGHT(arr, 3); // Rotate the first 3 elements

    printf("Rotated array: ");
    printArray(arr, n);

    return 0;
}
