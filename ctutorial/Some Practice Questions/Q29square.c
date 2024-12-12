#include<stdio.h>
#include<math.h>
int main(){
    double n=5;
    printf("%f",pow(n,2));//%d doesn't work here as pow(n,2) is a double one and store big value and implicitly convert into double value
    return 0;
}