#include <stdio.h>

void printTable(int n);

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);

    printTable(n); //argument/actual parameter
    return 0;
}

void printTable(int n) //parameter/formal parameter
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i*n);
    }
}