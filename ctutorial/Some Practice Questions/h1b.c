//To find a cube of number n given by user 
#include<stdio.h>
int main()
{
int n,cube; //variable declaration
printf("Enter a number n:");
scanf("%d",&n);
cube=n*n*n;
printf("The cube of given number n is %d",cube);
return 0;
}