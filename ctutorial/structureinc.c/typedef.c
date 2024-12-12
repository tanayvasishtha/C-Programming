#include<stdio.h>

typedef struct student{
    int roll;
    float cgpa;
    char name[100];
}stu;


int main(){
    stu s1;
    s1.cgpa=9.2;
    s1.roll=1664;
    printf("student roll no is %f\n",s1.cgpa);
    return 0;
}