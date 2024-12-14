#include <stdio.h>
#include <stdlib.h>

void comp(int *a, int *b)
{

    (*a > *b) ? printf("%d is greater than %d", *a, *b) : ((*a < *b) ? printf("%d is smaller than %d", *a, *b) : printf("Both numbers are the same"));
}

int main()
{
    int i, j;

    printf("Enter two numbers: ");
    scanf("%d %d", &i, &j);

    comp(&i, &j);

    printf("\n");

    return 0;
}