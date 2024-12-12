#include<stdio.h>
#include<string.h>
int main(){
char firststr[]="Apple";
char secstr[]="Banana";
//printf("%d",strcmp(firststr,secstr));//here we will get -1 or negative value due to the comparison between first value of letters on the basis of their ascii values 
printf("%d",strcmp(secstr,firststr));//here we will get +1 or positive output due to the same reason as mentioned above
}