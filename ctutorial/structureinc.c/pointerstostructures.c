#include<stdio.h>
struct student{
int roll;
};
int main(){
struct student s1={1664};
printf("student roll=%d\n",s1.roll);

struct student *ptr=&s1;
printf("Student roll=%d\n",(*ptr).roll);//*ptr gives the value at the adress of s1 so to search particular value at s1 for eg roll no then we can use it in the given format
return 0;    
}