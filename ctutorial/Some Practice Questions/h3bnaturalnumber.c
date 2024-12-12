// to find is a given nujmber is a natural number or not
#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    printf("Enter a natural number");
    scanf("%d", &x);

    if (x > 0)
        printf("The given number is a natural number");
    else if(x<0)
        printf("The given number is not a natural number");
    else
     printf("rehene de");
    return 0;
}