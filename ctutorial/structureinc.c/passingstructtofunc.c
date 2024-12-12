// passing structure to functions
#include <stdio.h>
// user defined
struct student
{
    int roll;
    float cgpa;
    char name[1000];//array is important to save the the characters of name in it
};

void printInfo(struct student s1); // if we declare it before struct then it will give error

int main()
{
    struct student s1 = {1664, 9.2, "Tanay"};
    s1.roll=12222;//it will change the roll no fully
    printInfo(s1);
    return 0;
}
void printInfo(struct student s1)
{
    printf("Student information\n");
    printf("student.roll=%d\n", s1.roll);
    printf("Student.cgpa=%f\n", s1.cgpa);
    printf("student.name=%s\n", s1.name);
    s1.roll=1300;//it will not change the roll no as the function is copy of the argument made above in the main function
}