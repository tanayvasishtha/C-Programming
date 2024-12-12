#include<stdio.h>

void display(int arr[],int size){
    //code for traversal
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}
//1,2,3,4,65,5,6
int indinsertion(int arr[],int size,int element, int capacity,int index){
//code for insertion
if(size>=capacity){
    return -1;//when there is no capacity left
}

for(int i=size-1;i>=index;i--){
arr[i+1]=arr[i];
}
arr[index]=element;
return 1;
}

int main(){
    int arr[100]={0,1,2,3,4};
    int size=5, element=45,index=3;
    display(arr,size);
    indinsertion(arr,size,element,100,index);
    size=size+1;
    display(arr,size);
    return 0;
}