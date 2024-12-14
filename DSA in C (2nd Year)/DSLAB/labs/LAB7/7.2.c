// Write a menu driven program to implement linear queue operations
// such as Enqueue, Dequeue, IsEmpty, Traverse
// using single linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *F = NULL;
struct node *R = NULL;

void enqueue(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (!new)
    {
        printf("MEMORY ALLOCATION FAILED!\n");
        return;
    }
    new->data = val;
    new->next = NULL;

    if (!F)
    {
        F = R = new;
    }
    else
    {
        R->next = new;
        R = new;
    }
}

void dequeue()
{
    if (!F)
    {
        printf("UNDERFLOW!\n");
        return;
    }
    else
    {
        struct node *rem = F;
        printf("Dequeued data: %d\n", rem->data);
        F = F->next;
        free(rem);
    }
}

int isEmpty()
{
    return !F ? 1 : 0;
}

void print()
{
    if (!F)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
        struct node *p = F;
        while (p)
        {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}
int main()
{
    int ch;
    printf("\nMain Menu \n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Traverse\n5. Exit");

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
            print();
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}