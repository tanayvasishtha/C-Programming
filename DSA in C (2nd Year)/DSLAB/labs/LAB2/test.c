#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int F, R;
    int array[MAX_SIZE];
};

struct Stack
{
    struct Queue *Q1;
    struct Queue *Q2;
};

// Function to enqueue an element into a queue
void enqueue(struct Queue *Q, int item)
{
    if ((Q->R + 1) % MAX_SIZE == Q->F)
    {
        printf("Queue is full\n");
        return;
    }

    if (Q->F == -1)
    {
        Q->F = Q->R = 0;
    }
    else
    {
        Q->R = (Q->R + 1) % MAX_SIZE;
    }

    Q->array[Q->R] = item;
}

// Function to dequeue an element from a queue
int dequeue(struct Queue *Q)
{
    if (Q->F == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int item = Q->array[Q->F];

    if (Q->F == Q->R)
    {
        // Only one element in the queue
        Q->F = Q->R = -1;
    }
    else
    {
        Q->F = (Q->F + 1) % MAX_SIZE;
    }

    return item;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item)
{
    enqueue(stack->Q1, item);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (stack->Q1->F == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    // Move all elements from queue1 to queue2 except the last one
    while (stack->Q1->F != stack->Q1->R)
    {
        enqueue(stack->Q2, dequeue(stack->Q1));
    }

    // Dequeue the last element from queue1
    int y = dequeue(stack->Q1);

    // Swap queue1 and queue2
    struct Queue *temp = stack->Q1;
    stack->Q1 = stack->Q2;
    stack->Q2 = temp;

    return y;
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    stack->Q2 = (struct Queue *)malloc(sizeof(struct Queue));

    stack->Q1->R = stack->Q1->F = -1;
    stack->Q2->R = stack->Q2->F = -1;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    push(stack, 40);

    printf("Popped element: %d\n", pop(stack));

    free(stack->Q1);
    free(stack->Q2);
    free(stack);

    return 0;
}
