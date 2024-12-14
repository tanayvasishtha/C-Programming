/*Aim of the program: Using
recursion, write a program in C/C++ to find the sum of odd position values of a
set of integers (stored in a disk file). Read all values from the disk
file and store the result in a separate file. 


Input:  The
disk file (say, inputValues.dat) containing values 10, -15, 55, 75, -20, -40,
85, 30, -5, -50.

Output: The output
file (say, sumValue.dat) contains 125 (as 10+55 -20+85-5=125).*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int sum = 0;
int count = 0;

void sumOfOddPositionValues(int n, FILE *fp) {
    if (n > 0) {
        sumOfOddPositionValues(n - 1, fp);
        int num;
        fscanf(fp, "%d", &num);
        if (n % 2 == 1) {
            sum += num;
            count++;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s inFile.dat outFile.dat\n", argv[0]);
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");

    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    sumOfOddPositionValues(10, inFile);
    fprintf(outFile, "The sum of odd position values is %d\n", sum);

    fclose(inFile);
    fclose(outFile);
    outFile = fopen(argv[2], "r");
    char line[100];
    while (fgets(line, sizeof(line), outFile) != NULL) {
        printf("%s", line);
    }
    fclose(outFile);
    return 0;
}



































