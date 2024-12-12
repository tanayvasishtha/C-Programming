#include <stdio.h>
int sum(int a, int b); //function prototype
//function call
int main()
{
    int a, b;

    printf("Enter the first number");
    scanf("%d", &a);
    printf("enter the second number");
    scanf("%d", &b);
    int s = sum(a, b);
    printf("sum is %d", s);
    return 0;
}
//function definition
int sum(int x, int y)
{
    return x + y;
}
