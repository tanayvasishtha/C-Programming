#include<stdio.h>
struct student{
int roll;
};
int main(){
struct student s1={1664};
printf("student roll=%d\n",s1.roll);//dot operator

struct student *ptr=&s1;
printf("Student.roll with ptr=%d\n",(*ptr).roll);//pointer to structures
printf("student->roll=%d\n",ptr->roll);//with arrow operator
return 0;//all the three give the same output    
}
