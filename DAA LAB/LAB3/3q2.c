/*3.2 Aim of the program: Write a menu driven program to sort a list of elements in ascending
order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
output file can be used for sorted elements. After sorting display the content of the output file
along with number of comparisons. Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning.
Note#
● The worst-case behavior for quicksort occurs when the partitioning routine produces one
subproblem with n-1 elements and one with 0 elements. The best-case behaviour
occurred in most even possible split, PARTITION produces two subproblems, each of
size no more than n/2.

● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40…..,
Store the result in “outQuickAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60….,
Store the result in “outQuickDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …,
Store the result in “outQuickRand.dat”
Sample Input from file:
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparison_count = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        comparison_count++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int* best_case, int* worst_case) {
    if (low < high) {
        int pi = partition(arr, low, high);

        if (pi == low || pi == high - 1) {
            (*worst_case)++;
        } else if (pi == (low + high) / 2) {
            (*best_case)++;
        }

        quickSort(arr, low, pi - 1, best_case, worst_case);
        quickSort(arr, pi + 1, high, best_case, worst_case);
    }
}

int read_file(const char* filename, int arr[], int max_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    int i = 0;
    while (i < max_size && fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }

    fclose(file);
    return i;
}

void write_file(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void display_menu() {
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
}

int main() {
    int arr[500];
    int n;
    char input_file[20], output_file[20];
    int best_case, worst_case;

    while (1) {
        display_menu();
        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                strcpy(input_file, "inAsce.dat");
                strcpy(output_file, "outQuickAsce.dat");
                break;
            case 2:
                strcpy(input_file, "inDesc.dat");
                strcpy(output_file, "outQuickDesc.dat");
                break;
            case 3:
                strcpy(input_file, "inRand.dat");
                strcpy(output_file, "outQuickRand.dat");
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                continue;
        }

        n = read_file(input_file, arr, 500);
        if (n == 0) {
            printf("No data to sort.\n");
            continue;
        }

        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        comparison_count = 0;
        best_case = 0;
        worst_case = 0;

        quickSort(arr, 0, n - 1, &best_case, &worst_case);

        write_file(output_file, arr, n);
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparison_count);
        if (worst_case > 0 && best_case == 0) {
            printf("Scenario: Worst-case partitioning\n");
        } else if (best_case > 0 && worst_case == 0) {
            printf("Scenario: Best-case partitioning\n");
        } else {
            printf("Scenario: Mixed partitioning\n");
        }
    }

    return 0;
}