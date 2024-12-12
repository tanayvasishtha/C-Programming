#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr=(int*)malloc(10*sizeof(int));
    
    for(int i=0;i<10;i++){
        scanf("%d",&ptr[i]);
        ptr[i]=7*(i+1);
        printf("\n7 x %d = %d \n",(i+1),ptr[i]);
    }
printf("\nAfter reallocation\n");

 ptr=realloc(ptr,15*sizeof(int));
 for(int i=0;i<15;i++){
        scanf("%d",&ptr[i]);
        ptr[i]=7*(i+1);
        printf("\n7 x %d = %d \n",(i+1),ptr[i]);
    }
}