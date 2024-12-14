/*4.1 Aim of the program:
Define a struct person as follows:
struct person
{
int id;
char *name;
int age;
int height;
int weight;
};
Write a menu driven program to read the data of ‘n’ students from a file and store them in a
dynamically allocated array of struct person. Implement the min-heap or max-heap and its
operations based on the menu options.
Sample Input/Output:
MAIN MENU (HEAP)

1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit
Enter option: 1
Id Name Age Height Weight(pound)
0 Adarsh Hota 39 77 231
1 Levi Maier 56 77 129
2 Priya Kumari 63 78 240
3 Dorothy Helton 47 72 229
4 Florence Smith 24 75 171
5 Erica Anyan 38 73 102
6 Norma Webster 23 75 145
Enter option: 4
Weight of youngest student: 65.77 kg
Note#: Other menu choices are similarly verified.*/




#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void readData(struct person *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Id: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Height: ");
        scanf("%d", &students[i].height);
        printf("Weight: ");
        scanf("%d", &students[i].weight);
    }
}

void createMinHeap(struct person *students, int n)
{
    // Implementation of creating a min-heap based on age
    // ...
}

void createMaxHeap(struct person *students, int n)
{
    // Implementation of creating a max-heap based on weight
    // ...
}

void displayWeightOfYoungest(struct person *students, int n)
{
    // Implementation of displaying weight of the youngest person
    // ...
}

void insertNewPerson(struct person *students, int *n)
{
    // Implementation of inserting a new person into the min-heap
    // ...
}

void deleteOldestPerson(struct person *students, int *n)
{
    // Implementation of deleting the oldest person
    // ...
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct person *students = (struct person *)malloc(n * sizeof(struct person));

    int option;
    do
    {
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

        switch (option)
        {
        case 1:
            readData(students, n);
            break;
        case 2:
            createMinHeap(students, n);
            break;
        case 3:
            createMaxHeap(students, n);
            break;
        case 4:
            displayWeightOfYoungest(students, n);
            break;
        case 5:
            insertNewPerson(students, &n);
            break;
        case 6:
            deleteOldestPerson(students, &n);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    } while (option != 7);

    free(students);

    return 0;
}

