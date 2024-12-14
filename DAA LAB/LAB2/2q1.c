//Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
// file to binary using recursion. Store the binary value in a separate disc file.

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void decimalToBinary(int n, FILE *fp) {
    if (n > 1)
        decimalToBinary(n / 2, fp);
    fprintf(fp, "%d", n % 2);
}

int main(int argc, char *argv[]){
    if (argc != 4) {
        printf("Usage: %s number_of_numbers inFile.dat outFile.dat\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *inFile = fopen(argv[2], "r");
    FILE *outFile = fopen(argv[3], "w");

    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

int num;
    for(int i=0;i<n;i++){fscanf(inFile, "%d", &num);
        fprintf(outFile, "The binary equivalent of %d is ", num);
        decimalToBinary(num, outFile);
        fprintf(outFile, "\n");
    }

    fclose(inFile);
    fclose(outFile);

    // Display contents of output file
    outFile = fopen(argv[3], "r");
    char line[100];
    while (fgets(line, sizeof(line), outFile) != NULL) {
        printf("%s", line);
    }
    fclose(outFile);
    return 0;
    }