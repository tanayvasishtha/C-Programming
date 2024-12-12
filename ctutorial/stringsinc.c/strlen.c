#include<stdio.h>
#include<string.h>
int main(){
    char name[]="Tanay";
    int length=strlen(name);//here we used int length to assign strlen library function its integer value as 
    printf("length is:%d",length);//if we used her directly strlen function then it would have shown error due to %d and will recommend to use %lu so we typecasted it by using another int variable
    return 0;
}