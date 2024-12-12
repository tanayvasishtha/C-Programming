//write  function named slice which takes a string & returns a sliced string from index n to m

#include<stdio.h>
#include<string.h>

void slice(char str[],int n,int m);


int main(){
 char str[] ="HELLOWORLD";
 slice(str,3,6);
 return 0;
}

void slice(char str[],int  n, int m){//n & m are valid values
    char newstr[100];
    int j=0;
    for(int i=n,j=0;i<=m;i++,j++){
        newstr[j]=str[i];
    }
newstr[j]='\0';
puts(newstr);
}
