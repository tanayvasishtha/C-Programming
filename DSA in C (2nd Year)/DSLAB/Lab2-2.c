#include <stdio.h>
#include <stdlib.h>

void nonZero(int **a, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                counter++;
            }
        }
    }

    printf("No. of non-zero elements: %d\n", counter);
}

void upperTri(int **a, int n)
{
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}
void AboveBelow(int **a, int n)
{
    printf("Just above the diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    printf("Just below the diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter size of the square matrix: ");
    scanf("%d", &n);
    int **a = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter elements of the matrix: ");
            scanf("%d", &a[i][j]);
        }
    }

    nonZero(a, n);

    upperTri(a, n);

    AboveBelow(a, n);

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}