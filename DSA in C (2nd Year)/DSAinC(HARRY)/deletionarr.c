#include<stdio.h>

void display(int arr[],int n){
    //code for traversal
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
//1,2,3,4,65,5,6
int inddeletion(int arr[],int size,int index){
for(int i=index;i<size-1;i++){
arr[i]=arr[i+1];
return 1;
}}

int main(){
    int arr[100]={0,1,2,3,4};
    int size=5,index=0;
    display(arr,size);
    inddeletion(arr,size,index);
    size=size-1;
    display(arr,size);
    return 0;
}