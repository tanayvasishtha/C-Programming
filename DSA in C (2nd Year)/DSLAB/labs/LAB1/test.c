#include <stdio.h>

int main()
{
    int first, second;
    printf("Enter the highest degree of the first polynomial: ");
    scanf("%d", &first);
    int a[first + 1];

    for (int i = 0; i < first + 1; i++)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the highest degree of the second polynomial: ");
    scanf("%d", &second);
    int b[second + 1];

    for (int i = 0; i < second + 1; i++)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &b[i]);
    }

    int c[first + 1][second + 1];

    for (int i = 0; i < first + 1; i++)
    {
        for (int j = 0; j < second + 1; j++)
        {
            c[i][j] = a[i] * b[j];
        }
    }

    int rows = first + 1, cols = second + 1;

    for (int i = 0; i < rows + cols - 1; i++)
    {
        int sum = 0, row, col;
        if (i < rows)
        {
            row = i;
        }
        else
        {
            row = rows - 1;
        }

        if (i < rows)
        {
            col = 0;
        }
        else
        {
            col = i - rows + 1;
        }

        while (row >= 0 && col < cols)
        {
            sum += c[row][col];
            row--;
            col++;
        }

        printf("%dx^%d + ", sum, i);
    }
    printf("\b\b ");

    return 0;
}
