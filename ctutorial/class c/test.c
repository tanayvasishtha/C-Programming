#include <stdio.h>
void sort(int *num, int s);
int main()
{
    int num[10];
    int *ptr = num;

    printf("Enter  10 numbers:\n\t");

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", i + 1);
        scanf("%d\t", ptr + i);
    }
    sort(num, 10);
    printf("Sorted numbers\n\t");

    for (int i = 0; i < 10; i++)
    {
        printf("%d", *(ptr + i));
    }
    return 0;
}

void sort(int *num, int s)
{
    int i, j, temp;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < s - i - 1; j++)
        {
            if ((num + j) > (num + j + 1))
            {
                temp = *(num + j);
                *(num + j) = *(num + j + 1);
                *(num + j + 1) = temp;
            }
        }
    }
}
