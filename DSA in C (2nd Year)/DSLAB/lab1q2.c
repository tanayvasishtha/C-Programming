/*Write a program to create an array of n elements using dynamic memory allocation.
Calculate sum of all the prime elements of the array using function and de-allocate the memory
of the array after its use.*/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size;
    int sum = 0;
    
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    int *arr = (int*)malloc(size * sizeof(int));

    printf("Enter the array elements: ");
    for (int j = 0; j < size; j++) {
        scanf("%d", arr + j);
    }
    
    for (int j = 0; j < size; j++) {
        if (isPrime(arr[j])) {
            sum += arr[j];
        }
    }

    printf("Sum of prime elements: %d\n", sum);
    
    free(arr);
    return 0;
}
