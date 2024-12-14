// Write a menu driven program to create a stack using array and perform the following
// operation using function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top = -1;
int Arr[MAX];

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
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
    }
    else
    {
        printf("Popped element: %d\n", Arr[top]);
        top = top - 1;
    }
}

int isEmpty()
{
    return top == -1 ? 1 : 0;
}

int isFull()
{
    return top == MAX - 1 ? 1 : 0;
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
    int ch;

    while (1)
    {
        printf("\nMain Menu \n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;

        case 5:
            print();
            break;

        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
