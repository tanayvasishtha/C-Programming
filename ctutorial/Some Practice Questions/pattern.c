#include <stdio.h>
int main()
{
    int i, n, j;
    printf("enter a number", n);
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        for (j = i; j >= 1; j--)
            printf("%d\n", n);
    }
    return 0;
}