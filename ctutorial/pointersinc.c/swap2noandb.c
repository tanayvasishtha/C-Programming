//swapping of two numbers a and b
#include<stdio.h>


// //call by value
// void swap(int a,int b);

// int main(){
// int x=3;
// int y=5;
// swap(x,y);
// printf("x=%d,y=%d\n",x,y);
// return 0;
// }

// void swap(int a,int b){

//     int t=a;
//     a=b;
//     b=t;
//     printf("a=%d &b=%d",a,b);
// }
// //call by value gave the same output that means it doesnot swap so we have to use call by reference 

void _swap(int *a,int *b);

int main(){
    int x=3,y=5;
    _swap(&x,&y);
    printf("x=%d & y=%d\n",x,y);
    return 0;
}


//call by reference
void _swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}