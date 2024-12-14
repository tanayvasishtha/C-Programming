#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, count1, row2, col2, count2;

    printf("Enter sparse matrix-1 in 3-tuple format: ");
    scanf("%d %d %d", &row1, &col1, &count1);

    int **A = (int **)malloc(3 * sizeof(int *));

    for (int r = 0; r < 3; r++)
    {
        A[r] = (int *)malloc(count1 * sizeof(int));
    }

    for (int k = 0; k < count1; k++)
    {
        scanf("%d %d %d", &A[0][k], &A[1][k], &A[2][k]);
    }

    printf("Enter sparse matrix-2 in 3-tuple format: ");
    scanf("%d %d %d", &row2, &col2, &count2);

    int **B = (int **)malloc(3 * sizeof(int *));

    for (int r = 0; r < 3; r++)
    {
        B[r] = (int *)malloc(count2 * sizeof(int));
    }

    for (int k = 0; k < count2; k++)
    {
        scanf("%d %d %d", &B[0][k], &B[1][k], &B[2][k]);
    }

    int **C = (int **)malloc(3 * sizeof(int *));

    for (int r = 0; r < 3; r++)
    {
        C[r] = (int *)malloc((count1 + count2) * sizeof(int));
    }

    int i = 0, j = 0, k = 0;
    while (i < count1 && j < count2)
    {
        if (A[0][i] < B[0][j] || (A[0][i] == B[0][j] && A[1][i] < B[1][j]))
        {
            C[0][k] = A[0][i];
            C[1][k] = A[1][i];
            C[2][k] = A[2][i];
            i++;
        }
        else if (A[0][i] == B[0][j] && A[1][i] == B[1][j])
        {
            C[0][k] = A[0][i];
            C[1][k] = A[1][i];
            C[2][k] = A[2][i] + B[2][j];
            i++;
            j++;
        }
        else if (A[0][i] > B[0][j] || (A[0][i] == B[0][j] && A[1][i] > B[1][j]))
        {
            C[0][k] = B[0][j];
            C[1][k] = B[1][j];
            C[2][k] = B[2][j];
            j++;
        }
        k++;
    }

    printf("Resultant Matrix in 3-tuple format:\n");
    for (int m = 0; m < k; m++)
    {
        printf("%d %d %d\n", C[0][m], C[1][m], C[2][m]);
    }

    for (int r = 0; r < 3; r++)
    {
        free(A[r]);
        free(B[r]);
        free(C[r]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
