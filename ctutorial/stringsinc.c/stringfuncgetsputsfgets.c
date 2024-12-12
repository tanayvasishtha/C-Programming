#include<stdio.h>
int main(){
    char str[100];
    //gets(str); we can use gets but its unsafe so we use fgets instead
    fgets(str,100,stdin);
    puts(str);
    return 0;
}