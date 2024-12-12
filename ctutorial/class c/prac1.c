#include <stdio.h>
void min();
void max();

int main()
{
    int a;
    int b;
    printf("Enter the number of rows and columns\n");
    scanf("%d%d", &a, &b);
    int arr[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");3

    }
}

int min(int arr[][],int a,int b){int min=arr[0][0];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if (min>arr[i][j]) {
                min=arr[i][j];
            }
        }
    }
}