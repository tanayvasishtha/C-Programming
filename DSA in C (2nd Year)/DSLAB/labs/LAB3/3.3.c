#include <stdio.h>

int main()
{
    int max_degree;

    printf("Enter the maximum degree of x: ");
    scanf("%d", &max_degree);

    int poly1[max_degree + 1], poly2[max_degree + 1], result[max_degree + 1];

    printf("Enter Polynomial-1 coefficients from lowest degree to highest degree:\n");
    for (int i = 0; i <= max_degree; i++)
    {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2 coefficients from lowest degree to highest degree:\n");
    for (int i = 0; i <= max_degree; i++)
    {
        scanf("%d", &poly2[i]);
    }

    for (int i = 0; i <= max_degree; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }

    printf("Resultant Polynomial: ");
    for (int i = max_degree; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            printf("%dx^%d", result[i], i);
            if (i != 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");

    return 0;
}
