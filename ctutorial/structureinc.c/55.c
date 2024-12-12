//WAP TO STORE THE DATA OF 3 STUDENTS
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};

int main(){
    struct student s1;
    s1.roll= 22054184;
    s1.cgpa=9.2;
    // s1.name="TANAY";
    strcpy(s1.name,"TANAY");
    
    printf("student name = %s\n",s1.name);
    printf("student roll no= %d\n",s1.roll);
    printf("student cgpa= %f\n",s1.cgpa);


    struct student s2;
    s2.roll= 2203025;
    s2.cgpa=9.2;
    // s1.name="DHRUV";
    strcpy(s2.name,"DHRUV");
    
    printf("student name = %s\n",s2.name);
    printf("student roll no= %d\n",s2.roll);
    printf("student cgpa= %f\n",s2.cgpa);
    
    struct student s3;
    s3.roll= 22054119;
    s3.cgpa=9.2;
    // s1.name="ADI";
    strcpy(s3.name,"ADI");
    
    printf("student name = %s\n",s3.name);
    printf("student roll no= %d\n",s3.roll);
    printf("student cgpa= %f\n",s3.cgpa);
    return 0;
}