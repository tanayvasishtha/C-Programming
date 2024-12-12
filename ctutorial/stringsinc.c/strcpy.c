#include<stdio.h>
int main(){
    char oldstr[]="oldstr";
    char newstr[]="newstr";
    strcpy(newstr,oldstr);//it copies value of oldstr in newstr
    puts(newstr);//here vale of oldstr copies to newstr but oldstr value remains unchanged
    return 0;
} 