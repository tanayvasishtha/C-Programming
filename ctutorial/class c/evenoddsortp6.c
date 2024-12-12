// First input of 10 numbers then sorting them in even and odd
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
        for (j = 0; j < 9 - i; j++)//sorting loop
        {
            if ((b + j) > (b + j + 1))
            {
                t = *(b + j);
                *(b + j) = *(b + j + 1);
                *(b + j + 1) = t;
            }
        }
    }
    for (i = 0; i < 10; i++) //loop for even and odd sorting first even then odd
    {
        if (*(b + i) % 2 == 0)
            printf("%d  ", *(b + i));
    }
    for (i = 0; i < 10; i++)
    {
        if (*(b + i) % 2 != 0)
            printf("%d  ", *(b + i));
    }
    printf("\n");
    return 0;
}