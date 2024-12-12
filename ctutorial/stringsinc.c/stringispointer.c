#include<stdio.h>
int main(){
 char *canchange="Hello World";//if we want to change then we use pointer
 puts(canchange);
 canchange="Hello";
 puts(canchange);

 char cannotchange[]="Hello World";//we cannot modify the expression in array afterwards thatswhy we use pointers
 puts(cannotchange);
 //cannotchange="Hello"; it will show error as expression must be a modifiable value
 return 0;
}