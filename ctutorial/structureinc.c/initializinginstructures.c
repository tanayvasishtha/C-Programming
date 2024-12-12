#include<stdio.h>

//user defined
struct student{
    int roll;
    float cgpa;
    char name[100];
};

int main(){
  struct student s1={1664,8.9,"tanay"};
  printf("student roll=%d\n,student cgpa=%f\n, student name=%s\n",s1.roll,s1.cgpa,s1.name);
  return 0;

}