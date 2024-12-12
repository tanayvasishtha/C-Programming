#include<stdio.h>
int main(){
int a[5],*b=a,i;
	for(i=0;i<6;i++)
	{
		printf("Enter a number: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<6;i++)
	{
		printf("%d\n",*b++);
	}
	return 0;
}