// Write a menu driven program to create a linear queue
// using array and perform Enqueue, Dequeue, Traverse, IsEmpty,
// IsFull operations.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int F = -1;
int R = -1;
int Arr[MAX];

void enqueue(int data)
{
    if (R == MAX - 1)
    {
        printf("Overflow!\n");
    }
    else
    {
        R = R + 1;
        Arr[R] = data;
        if (F == -1)
        {
            F = 0;
        }
    }
}

void dequeue()
{
    if (F == -1)
    {
        printf("Underflow!\n");
        return;
    }
    else
    {
        printf("Dequeued element: %d\n", Arr[F]);
        if (F == R) // empty
        {
            F = -1;
            R = -1;
        }
        else
        {
            F = F + 1;
        }
    }
}

int isEmpty()
{
    return F == -1 ? 1 : 0;
}

int isFull()
{
    return R == MAX - 1 ? 1 : 0;
}

void print()
{
    if (F == -1)
    {
        printf("Underflow!\n");
        return;
    }
    else
    {
        for (int i = F; i <= R; i++)
        {
            printf("%d ", Arr[i]);
        }
    }
}

int main()
{
    int ch;
    printf("\nMain Menu \n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit");

    while (1)
    {
        printf("\nEnter option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty())
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("queue is not empty\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("queue is full\n");
            }
            else
            {
                printf("queue is not full\n");
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
