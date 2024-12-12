#include <stdio.h>
#define MAX 100

int top = -1;
int Arr[MAX];

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        Arr[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        printf("Popped element: %d", Arr[top]);
        top = top - 1;
    }
}

void print()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d  ", Arr[i]);
        }
    }
}

int main()
{
    printf("\n");
    push(1);
    push(2);
    push(3);
    print();
    printf("\n");
    pop();
    printf("\n");
    print();
    printf("\n");
    return 0;
}