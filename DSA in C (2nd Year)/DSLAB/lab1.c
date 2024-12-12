// 1.1 Write a program to read two numbers and compare the numbers using function call by address/ reference

// Sample Input: Enter two numbers: 50  80
// Sample Output: 50 is smaller than 80

// Sample Input: Enter two numbers: 40  10
// Sample Output: 40 is greater than 10

// Sample Input: Enter two numbers: 50  50
// Sample Output: Both numbers are same

#include <stdio.h>

int main()
{
  int a;
  int b;
  printf("Enter the first number:");
  scanf("%d", &a);
  printf("\n");
  printf("Enter second number:");
  scanf("%d", &b);
  // calling the function
  int com = comparision(&a, &b);

  switch (com)
  {
  case 1:
    printf(" %d is greater than %d ", a, b);
    break;
  case 2:
    printf(" %d is smaller than %d ", a, b);
    break;3
  default:
    printf(" Both numbers are same ");
    break;
  }
  return 0;
}


int comparision(int *a, int *b)
{
  // here the condition check wheather a or b is greater .
  if (*a > *b)
  {
    return 1;
  }
  else if (*b > *a)
  {
    return 2;
  
  ]}
}