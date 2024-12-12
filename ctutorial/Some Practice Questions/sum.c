#include <stdio.h>
int main()
{
    int n,i;
    int sum=0;
    printf("Enter the limit ", n);
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("the sum of first n natural numbers is %d\n", sum);
    }
    return 0;
}