#include<stdio.h>

//2students and their 3 subjects marks are to be stored
int main(){
int marks[2][3];//_ _ _ | _ _ _
marks[0][0]=99;
marks[0][1]=99;
marks[0][2]=89;

marks[1][0]=99;
marks[1][1]=99;
marks[1][2]=89;

printf("%d",marks[1][2]);
return 0;


}