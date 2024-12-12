//WAP TO FIND THE NUMBER OF NON-ZERO ELEMENTS IN A SPARSE MATRIX
#include<stdio.h>
#include<stdlib.h>
int main(){
 int A[20][20];
 int i,j,rows,columns,count; //initialization    
 printf("Enter the number of rows:"); //matrix formation
     scanf("%d",&rows);
 printf("Enter the number of columns:");
 scanf("%d",&columns);
 printf("Enter the elements of the matrix");
  for(i=0;i<rows;i++) //formation of matrix
  {
    for(j=0;j<columns;j++){
    scanf("%d",&A[i][j]);
    
            if (A[i][j] != 0)
            {
                count++;
            }
        }
    }

    int B[3][count];
    int x = 0;
    printf("i j value: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (A[i][j] != 0)
            {

                B[0][x] = i;
                B[1][x] = j;
                B[2][x] = A[i][j];
                x++;
            }
        }
    }

    for (int j = 0; j < count; j++)
    {
        printf("%d %d %d\n", B[0][j], B[1][j], B[2][j]);
    }

    return 0;
}