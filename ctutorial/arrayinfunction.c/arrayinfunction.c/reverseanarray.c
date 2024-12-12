//reverse an array in c
#include<stdio.h>
void reverse(int arr[],int n);
void printArray(int arr[],int n);
int main(){
int arr[]={5,4,3,2,1};
reverse(arr,5);
printArray(arr,5);
return 0;
}


void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[n-i-1]);
    }
    printf("\n");
}

void reverse(int arr[], int n){
    for(int i=0;n<n/2;i++){
        int firstVal=arr[i];
        int secondVal=arr[n-i-1];
        arr[i]=secondVal;
        arr[n-i-1]=firstVal;
    }
} 