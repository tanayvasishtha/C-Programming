#include <stdio.h>
int main()
{
    char name[50];
    scanf("%s", name);//no '&' symbol is needed in string 
    printf("your name is %s", name);
    printf("\n");
    char Name[] = "TANAY";
    char lastname[] = "VASISHTHA";
    printf("%s\n%s", Name, lastname);
    return 0;
}