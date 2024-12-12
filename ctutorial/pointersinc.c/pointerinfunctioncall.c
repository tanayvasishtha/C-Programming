
#include <stdio.h>
void square(int n);
void _square(int* n);//this shows that here a pointer will come

int main()
{
    int number = 4;
    printf("number=%d\n", number);
    square(number);
    _square(&number);
    printf("number=%d\n",number);
    return 0;
}
//call by value(where we pass value of variable as argument)
void square(int n)
{
    n = n * n;
    printf("square=%d\n", n);
}
//call by reference(where we pass address of variable as arguments)
void _square(int* n)
{
    *n=(*n)*(*n);
    printf("square=%d\n",*n);
}