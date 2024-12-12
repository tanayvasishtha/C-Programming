#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, count;
    printf("Enter sparse matrix in 3-tuple format: ");
    scanf("%d %d %d", &row, &col, &count);

    int **B = (int **)malloc(3 * sizeof(int *));

    for (int r = 0; r < 3; r++)
    {
        B[r] = (int *)malloc(count * sizeof(int));
    }

    for (int k = 0; k < count; k++)
    {
        scanf("%d %d %d", &B[0][k], &B[1][k], &B[2][k]);
    }

    int transposeRow = col;
    int transposeCol = row;

    // transpose
    for (int k = 0; k < count; k++)
    {
        // swap
        B[0][k] = B[0][k] + B[1][k];
        B[1][k] = B[0][k] - B[1][k];
        B[0][k] = B[0][k] - B[1][k];
    }

    printf("Transpose of sparse matrix:\n");
    printf("R C Element\n");
    for (int k = 0; k < count; k++)
    {
        printf("%d %d %d\n", B[0][k], B[1][k], B[2][k]);
    }

    free(B);
    return 0;
}
