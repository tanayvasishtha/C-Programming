/*Aim of the program: Write a program to sort a list of array elements (in descending order) using the Quick Sort technique. Collect the input data from a disc file and store the sorted elements in a separate output file. The program should count the number of comparisons. Discuss the Best and Worst case time complexity with the help of recurrence relation.*/
//ROLL NO 22054184 NAME TANAY VASISHTHA
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int* comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int* comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int arr[100];
    int n = 0;

    while (fscanf(inputFile, "%d", &arr[n]) != EOF) {
        n++;
    }

    int comparisons = 0;
    quickSort(arr, 0, n - 1, &comparisons);

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fprintf(outputFile, "\n Number of comparisons: %d\n", comparisons);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}