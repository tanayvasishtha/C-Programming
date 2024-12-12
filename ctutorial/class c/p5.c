// sorting of the first 10 number input by the user
#include <stdio.h>
int main()
{
    int a[11], *b = a, i, j, t;
    for (i = 0; i < 10; i++)
    {
        printf("Enter a number ");
        scanf("%d", &*b++);
    }
    b = a;
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", *b++);
    }
    printf("\n");
    b = a;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++) //bubble sort loop process
        {
            if ((b + j) > (b + j + 1))
            {
                t = *(b + j);
                (b + j) = (b + j + 1);
                *(b + j + 1) = t;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", *b++);
    }
    printf("\n");
    return 0;
}