#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} arr;

void createarray(arr *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void setval(arr *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element at index %d :",i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void show(arr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    arr marks;
    createarray(&marks, 10, 5);
    printf("Now we will start with our set value function\n");
    setval(&marks);
    printf("Now we will start with show function\n");
    show(&marks);
    return 0;
}