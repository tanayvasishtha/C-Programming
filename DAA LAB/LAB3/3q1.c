/*3.1 Aim of the program: Write a menu driven program to sort list of array elements using Merge
Sort technique and calculate the execution time only to sort the elements. Count the number of
comparisons.
Note#
● To calculate execution time, assume that single program is under execution in the CPU.
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40…..,
Store the result in “outMergeAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60….,
Store the result in “outMergeDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …,
Store the result in “outMergeRand.dat”

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparison_count = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int read_file(const char *filename, int arr[], int max_size) {
    FILE *file = fopen(filename, "r");
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

void write_file(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
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
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
}

int main() {
    int arr[500];
    int n;
    char input_file[20], output_file[20];
    clock_t start, end;
    double cpu_time_used;

    while (1) {
        display_menu();
        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                strcpy(input_file, "inAsce.dat");
                strcpy(output_file, "outMergeAsce.dat");
                break;
            case 2:
                strcpy(input_file, "inDesc.dat");
                strcpy(output_file, "outMergeDesc.dat");
                break;
            case 3:
                strcpy(input_file, "inRand.dat");
                strcpy(output_file, "outMergeRand.dat");
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

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double) (end - start)) * 1000000000 / CLOCKS_PER_SEC;

        write_file(output_file, arr, n);
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparison_count);
        printf("Execution Time: %.0f nanoseconds\n", cpu_time_used);
    }

    return 0;
}

