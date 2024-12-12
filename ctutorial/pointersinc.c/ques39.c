#include<stdio.h>

// void printAddress(int n);

// int main(){
// int n=4;
// printAddress(n);
// printf("address of n is:%u\n",&n);
// return 0;

// }

// void printAddress(int n){
//  printf("address of n is:%u\n",&n);
// }
// //in this code we can see both have different address due to call by value as a copy is being made 
// //therefore representing different address
void printAddress(int *n);

int main(){
int n=4;
 printAddress(&n);
 printf("address of n is:%u\n",&n);
 return 0;
}

void printAddress(int *n){
  printf("address of n is:%u\n",n);
}