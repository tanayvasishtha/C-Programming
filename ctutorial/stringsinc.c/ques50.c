#include<stdio.h>
#include<string.h>

int main(){
 char str[100];
 char ch;//we will input character ch into the str
 int i=0;//will track the index

 while(ch != '\n'){ //\n means when we click enter it changes line tht means it will stop after entering 
    scanf("%c",&ch);
    str[i]=ch;
    i++;
 }//it loop works as fgets
 str[i]='\0';// null character will append
 puts(str);
}