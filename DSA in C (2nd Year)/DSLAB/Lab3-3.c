#include <stdio.h>

int main()
{
    int maxDegree;

    printf("Enter maximum degree of x: ");
    scanf("%d", &maxDegree);

    int polyA[maxDegree + 1];
    int polyB[maxDegree + 1];
    int result[maxDegree + 1];

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = 0;
    }

    printf("Enter coefficients of Polynomial A from lowest degree to highest degree: ");
    for (int i = 0; i <= maxDegree; i++)
    {
        scanf("%d", &polyA[i]);
    }

    printf("Enter coefficients of Polynomial B: ");
    for (int i = 0; i <= maxDegree; i++)
    {
        scanf("%d", &polyB[i]);
    }

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = polyA[i] + polyB[i];
    }

    printf("Result Polynomial: ");
    for (int i = 0; i <= maxDegree; i++)
    {
        printf("%d", result[i]);
        if (i < maxDegree)
        {
            printf("x^%d + ", i);
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}
