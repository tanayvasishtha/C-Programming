#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void PrimeSum(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;

        for (int j = 2; j <= sqrt(*(a + i)); j++)
        {
            if (*(a + i) % j == 0)
            {
                ++counter;
                break;
            }
        }

        if (counter == 0 && (*(a + i)) > 1)
        {
            sum += (*(a + i));
        }
    }
    printf("Sum = %d\n", sum);
}

int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int *p = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter array element: ");
        scanf("%d", &(*(p + i)));
    }

    PrimeSum(p, n);
    free(p);

    printf("\n");
    return 0;
}