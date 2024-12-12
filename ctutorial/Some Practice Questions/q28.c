#include <stdio.h>
//function prototype 
void printNamaste();
void printBonjour();
//function definition
void printNamaste()
{
    printf("Namaste");
}

void printBonjour()
{
    printf("Bonjour");
}
//function call
int main()
{
    printf("Enter f for french and i for Indian:");
    char ch;
    scanf("%c", &ch);
    if (ch == 'I')
    {
        printNamaste();
    }
    else
    {
        printBonjour();
    }

    return 0;
}
