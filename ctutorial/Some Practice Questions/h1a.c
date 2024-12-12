//Perimeter of rectangle
#include<stdio.h>
int main()
{
 int a,b,peri; //variable declaration
 printf("Enter the sides of rectangle");
 scanf("%d%d",&a,&b);
 peri=2.0*(a+b); //formula of perimeter of rectangle
  printf("Perimeter of rectangle: %d",peri);
 return 0;
}