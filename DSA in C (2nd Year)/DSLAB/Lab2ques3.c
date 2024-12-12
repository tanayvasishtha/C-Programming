#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter number of rows and numer of columns: ");
    scanf("%d %d", &row, &col);

    int A[row][col];
    int counter = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter element: ");
            scanf("%d", &A[i][j]);

            if (A[i][j] != 0)
            {
                counter++;
            }
        }
    }

    int B[3][counter];
    int x = 0;

    printf("%d %d %d\n", row, col, counter);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (A[i][j] != 0)
            {

                B[0][x] = i;
                B[1][x] = j;
                B[2][x] = A[i][j];
                x++;
            }
        }
    }

    for (int k = 0; k < counter; k++)
    {
        printf("%d %d %d\n", B[0][k], B[1][k], B[2][k]);
    }

    return 0;
}