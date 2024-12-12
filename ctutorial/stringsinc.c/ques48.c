#include<stdio.h>
//ask the user to enter their first name& print it back to them.also try this with their fullname
int main(){
//  char firstName[40];
 char fullName[100];
 scanf("%s",fullName);
 printf("your full name is %s",fullName);
//  scanf("%s",firstName);
//  printf("your name is %s",firstName);
 return 0;
//In the output we can notice that the string only gives first name and last name is not written as scanf() cannot input multi-word strings with spaces

}