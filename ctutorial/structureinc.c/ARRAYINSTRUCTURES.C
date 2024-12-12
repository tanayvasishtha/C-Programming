#include<stdio.h>
#include<string.h>

struct student{
    int roll;
    float cgpa;
    char name[100];
};


int main(){
  struct student ece[100];
  ece[0].roll=1664;
  ece[0].cgpa=9.1;
  strcpy(ece[0].name,"tanay");
  printf("Roll no is=%d\n",ece[0].roll);
  printf("cgpa is=%f\n",ece[0].cgpa);
  printf("name=%s\n",ece[0].name);
  return 0;

}