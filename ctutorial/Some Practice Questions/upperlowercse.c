//to find if the given character is uppercase or lowercase
#include<stdio.h>
#include<math.h>
int main()
{
 char ch;
 printf("Enter a character:");
 scanf("%c",&ch);

 if(ch>='A' && ch<='Z')     //if ch>=97 || ch>='a' has the same meaning for the given compiler
 printf("the given character is upper case");
 else if(ch>='a'&& ch<='z')
 printf("The given character is lowercase");
 else
 printf("not a valid option");
 return 0;
}