/*1.3 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void read_numbers(const char *filename, int arr[], int *n) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%d", &arr[*n]) == 1 && *n < MAX_SIZE) {
        (*n)++;
    }
    fclose(fp);
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    const char *filename = "numbers.txt";

    read_numbers(filename, arr, &n);

    // Count duplicates and find most frequent element
    int duplicate_count = 0;
    int max_count = 0;
    int most_frequent = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                duplicate_count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_frequent = arr[i];
        }
    }

    printf("Total number of duplicate elements: %d\n", duplicate_count);
    printf("Most repeating element: %d\n", most_frequent);

    return 0;
}