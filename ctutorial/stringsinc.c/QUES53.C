// func to count the occurenc eof vowels in a string
#include <stdio.h>
#include<string.h>
int countvowels(char str[]);

int main()
{
    char str[] = "tanay";
    printf("vowels are :%d", countvowels(str));
    return 0;
}
int countvowels(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
}