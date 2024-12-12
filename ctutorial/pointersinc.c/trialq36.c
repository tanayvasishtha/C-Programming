//Question no 6
#include<stdio.h>
int main(){
 int x;
 int *ptr;

 ptr=&x;
 *ptr=0;

 printf("x=%d",x);//We should get both outputs as 0
 printf("*ptr=%d\n",ptr);

*ptr+=5;
printf("x=%d\n",x);//We should get both outputs as 5
printf("*ptr=%d\n",*ptr);

(*ptr)++;
printf("x=%d\n",x);//we should get 6 as our output in both the cases
printf("*ptr=%d\n",*ptr);
 return 0;
}