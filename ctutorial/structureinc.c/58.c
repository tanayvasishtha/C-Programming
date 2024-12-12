#include<stdio.h>

struct complex{
    int real;
    int imag;
};

int main(){
struct complex number1={5,8};
struct complex *ptr=&number1;
printf("real part=%d\n",ptr->real);
printf("imag part=%d\n",ptr->imag);
return 0;
}