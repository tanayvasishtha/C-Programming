#include <stdio.h>
int main()
{
    int num, i, fact = 1;
    printf("enter a number:");
    scanf("%d", &num);
    // calculate the factorial of positive number
    for (i = 1; i <= num; i++)
    {
        fact = fact * i;
    } // To print the factorial of the given number
    printf("The factorial of the num is%d", fact);
    return 0;
} 