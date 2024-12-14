#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int real;
    int imag;
} complex;

void sum(complex c1, complex c2)
{
    int RealSum = c1.real + c2.real;
    int imagSum = c1.imag + c2.imag;
    printf("Sum=%d+%di\n", RealSum, imagSum);
}

void multiply(complex *c1, complex *c2)
{
    int RealProduct = (c1->real * c2->real) - (c1->imag * c2->imag);
    int imagProduct = (c1->real * c2->imag) + (c1->imag * c2->real);
    printf("Product=%d+%di\n", RealProduct, imagProduct);
}

int main()
{
    complex c1, c2;
    printf("Enter complex number: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("Enter complex number: ");
    scanf("%d %d", &c2.real, &c2.imag);

    while (1)
    {
        int choice;
        printf("\nMENU\n1. addition\n2. multiplication\nquit(any int)\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            sum(c1, c2);
            printf("\n\n");
        }

        else if (choice == 2)
        {
            multiply(&c1, &c2);
            printf("\n\n");
        }

        else
        {
            break;
        }
    }
    return 0;
}
