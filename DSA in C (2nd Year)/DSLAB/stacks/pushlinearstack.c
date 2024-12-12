#include <stdio.h>
#include <stdlib.h>
// function declaration
int arr[100];

int t;
int n;
int top = -1;

void push(int n)
{

    if (top = t - 1)
    {
        printf("stack overflow");
        return;
    }
    else
    {
        top = top + 1;
        arr[top] = n;
    }
}
// main function
int main()
{
    // testcase
    printf("Enter no of testcases: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        push(n);
    }
    for (int j = 0; j < t; j++)
    {
        printf("%d", arr[j]);
    }
}