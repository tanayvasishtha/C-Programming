#include <stdio.h>

#define MAX 101

void insert(int a[], int elem, int pos, int *n)
{

    for (int i = *n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos] = elem;
    (*n)++;
}

void delete(int a[], int pos, int *n)
{
    for (int i = pos; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    --(*n);
}

void search(int a[], int elem, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (a[i] == elem)
        {
            printf("Element is positioned at index %d", i);
            return;
        }
    }

    printf("Element is not in the array.");
}

void trav(int a[], int *n)
{
    printf("Array elements: ");
    for (int i = 0; i < *n; i++)
    {
        printf(" %d", a[i]);
    }
}

int main()
{
    int a[MAX], n;

    printf("Enter size n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter array elements: ");
        scanf("%d", &a[i]);
    }

    int choice, element, position;

    while (1)
    {
        printf("\n\n**MENU**\n1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n5. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter element and position for insertion: ");
            scanf("%d %d", &element, &position);
            insert(a, element, position, &n);
        }

        if (choice == 2)
        {
            printf("Enter position for deletion: ");
            scanf("%d", &position);
            delete (a, position, &n);
        }

        if (choice == 3)
        {
            printf("Enter element to be searched: ");
            scanf("%d", &element);
            search(a, element, &n);
        }

        if (choice == 4)
        {
            trav(a, &n);
        }

        if (choice == 5)
        {
            printf("quitting...");
            break;
        }
    }

    printf("\n\n");

    return 0;
}
