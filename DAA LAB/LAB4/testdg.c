#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

// Function to swap two elements
void swap(struct person *x, struct person *y) {
    struct person temp = *x;
    *x = *y;
    *y = temp;
}

// Function to max-heapify
void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight) {
        largest = left;
    }

    if (right < n && arr[right].weight > arr[largest].weight) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to min-heapify
void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age) {
        smallest = left;
    }

    if (right < n && arr[right].age < arr[smallest].age) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min-heap based on age
void buildMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to build a max-heap based on weight
void buildMaxHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to insert a new person into min-heap
void insertMinHeap(struct person **arr, int *n, struct person newPerson) {
    *arr = (struct person *)realloc(*arr, (*n + 1) * sizeof(struct person));
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int i = (*n)++;
    (*arr)[i] = newPerson;

    while (i != 0 && (*arr)[(i - 1) / 2].age > (*arr)[i].age) {
        swap(&(*arr)[i], &(*arr)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the oldest person from min-heap
void deleteOldestPerson(struct person arr[], int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
}

// Function to find the weight of the youngest person
void weightOfYoungestPerson(struct person arr[], int n) {
    if (n == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Weight of youngest person: %.2f kg\n", arr[0].weight * 0.453592);
}

// Function to read data from file
void readData(struct person **arr, int *n) {
    FILE *file = fopen("data41.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    fscanf(file, "%d", n);
    *arr = (struct person *)malloc(*n * sizeof(struct person));
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %s %d %d %d", &(*arr)[i].id, (*arr)[i].name, &(*arr)[i].age, &(*arr)[i].height, &(*arr)[i].weight);
    }

    fclose(file);
}

int main() {
    struct person *arr = NULL;
    int n = 0;
    int option;
    struct person newPerson;

    while (1) {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                readData(&arr, &n);
                break;
            case 2:
                buildMinHeap(arr, n);
                printf("Min-heap based on age has been created.\n");
                break;
            case 3:
                buildMaxHeap(arr, n);
                printf("Max-heap based on weight has been created.\n");
                break;
            case 4:
                weightOfYoungestPerson(arr, n);
                break;
            case 5:
                printf("Enter new person's details (ID Name Age Height Weight): ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                insertMinHeap(&arr, &n, newPerson);
                printf("Person inserted into the min-heap.\n");
                break;
            case 6:
                deleteOldestPerson(arr, &n);
                printf("Oldest person deleted from the min-heap.\n");
                break;
            case 7:
                free(arr);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}