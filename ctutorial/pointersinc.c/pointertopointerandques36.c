#include <stdio.h>
int main()
{
    // float price = 100.00;
    // float *ptr = &price;
    // float **pptr = &ptr;
    // printf("%f\n",*ptr);
    // printf("%f",**pptr);
    int i=5;
    int *ptr=&i;
    int **pptr=&ptr;
    printf("%d\n",**pptr);
    return 0;
}