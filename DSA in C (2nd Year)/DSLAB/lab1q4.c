/*1.4 Write a menu driven program to create a structure to represent complex number and
perform the following operation using function :
1. addition of two complex number (call by value)
2. multiplication of two complex number (call by address)*/

#include <stdio.h>

// Using a structure to declare a complex number
struct Complex
{
    float imaginary;
    float real;
};

// Function to add two complex numbers (call by value)
struct Complex addcomplex(struct Complex num1, struct Complex num2)
{
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;

    return result;
}

// Function to multiply two complex numbers (call by reference/address)
void multiplingcomplexnum(struct Complex *num1, struct Complex *num2, struct Complex *result)
{
    result->real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    result->imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
}

int main()
{
    struct Complex num1, num2, result;
    int choice;

    // Input complex numbers
    printf("Enter complex number 1 (real imaginary): ");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("Enter the complex number 2 (real imaginary): ");
    scanf("%f %f", &num2.real, &num2.imaginary);

    do
    {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            result = addcomplex(num1, num2);
            printf("Sum = %.2f+%.2fi\n", result.real, result.imaginary);
            break;

        case 2:
            multiplingcomplexnum(&num1, &num2, &result);
            printf("Multiplication = %.2f+%.2fi\n", result.real, result.imaginary);
            break;

        default:
            printf("Invalid choice, please try again!\n");
        }

    } while (choice != 1 && choice != 2);

    return 0;
}
