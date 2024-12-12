#include<stdio.h>
int main(){
int *a[10]={100,30,20,3,43,23,22,32};

printf("%d\n",a[0]+1);
printf("%d\n",&a);
printf("%d\n",&a[0]+1);
printf("%d\n",&a+1);
printf("%d\n",*a+1);
return 0;
}