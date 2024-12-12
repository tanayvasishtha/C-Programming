#include<stdio.h>
#include<stdlib.h>
#define N 100 
struct myArray{      //structure declaration
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize){  //function declaration
                                                            //creation of array
    // (*a).total_size=tSize;
    // (*a).used_size=uSize;
    // (*a).ptr=(int *)malloc(tSize*sizeof(int));
    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr=(int *)malloc(tSize*sizeof(int));
}


void setval(struct myArray *a){//saves value
    int n;
    for(int i=0;i<a->used_size;i++){
        printf("enter element at index %d : ",i);
        scanf("%d",&n);
     (a->ptr)[i]=n;
    }
}

void show(struct myArray *a){//prints value
    for(int i=0;i<a->used_size;i++){
        printf("%d\n",(a->ptr)[i]);
    }
}


int main(){ 
    struct myArray marks; //structure call
    createArray(&marks,10,5);
    printf("We are running setval now\n");
    setval(&marks);
    printf("We are running show now\n");
    show(&marks); //function call
    return 0;
}