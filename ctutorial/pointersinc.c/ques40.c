#include <stdio.h>

void doWork(int a, int b, int *sum, int *product, int *average);

int main()
{
    int a = 3, b = 5;
    int sum, product, average;
    doWork(a,b,&sum,&product,&average);
    printf("sum=%d, prod=%d, avg=%d",sum,product,average);
    return 0;
}

void doWork(int a, int b, int *sum, int *product, int *average)
{
    *sum = a + b;
    *product = a * b;
    *average = (a + b) / 2;
}