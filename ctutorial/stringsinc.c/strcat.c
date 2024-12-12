#include<stdio.h>
#include<string.h>
int main(){
char firststr[100]="Hello";
char secstr[]="World";
strcat(firststr,secstr);
//puts(secstr);//if we use secstr only the "WORLD" IS PRINTED EVEN AFTER USING CONCATENATE FUNCTION BECAUSE THE CONCATENATION OCCURS IN FIRSTSTR 
puts(firststr);
}//AND IN FIRSTSTR "HELLOWORLD" IS STORED IN IT WITHOUT ANY SPACE