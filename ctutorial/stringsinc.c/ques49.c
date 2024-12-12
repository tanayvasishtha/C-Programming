#include <stdio.h>
// wap to input user name & print its length

int countLength(char arr[]);

int main()
{
    char name[100];
    fgets(name, 100, stdin);
    printf("Length is:%d", countLength(name));
    return 0;
}

int countLength(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count-1;//important step as it calculates +1 WHEN we written count alone
}