#include <stdio.h>
int main()
{
    float base;
    printf("Enter the base salary of employee:");
    scanf("%f", &base);
    if (base <= 4000)
        printf("The gross salary of the employee is %f", base * 0.1 + base * 0.5 + base);
    else if (base <= 8000)
        printf("The gross salary of the employee is %f", base * 0.2 + base * 0.6 + base);
    else if (base <= 12000)
        printf("The gross salary of the employee is %f", base * 0.25 + base * 0.70 + base);
    else
    (base >= 12001);
        printf("The gross salary of the employee is %f", base * 0.3 + base * 0.80 + base);
    return 0;
}