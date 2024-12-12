#include <stdio.h>
int main()
{
    int arr[] = {3, 4, 5, 6, 7, 8, 11, 12};
    int *t = arr;
    printf("%d", *(t + 4));
    return 0;
}
