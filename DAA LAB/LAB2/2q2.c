/*2.3 Aim of the program: Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from a file and store the result in a separate file.
Note# Source file name and destination file name taken from command line arguments. The
source file must contain at least 20 pairs of numbers.
Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
Contents of the output disc file “outGcd.dat” as
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
Terminal Input:
$gcc lab2q2.c -o lab2q2
$./lab2q2 inGcd.dat outGcd.dat
Output: Display the gcd stored in the output file outGcd.dat*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file %s\n", argv[1]);
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file %s\n", argv[2]);
        fclose(inputFile);
        return 1;
    }

    int count = 0;
    int num1, num2;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        int g = gcd(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, g);
        count++;
    }

    fclose(inputFile);
    fclose(outputFile);

    if (count < 20) {
        fprintf(stderr, "Warning: Input file contains less than 20 pairs of numbers\n");
    }

    printf("GCD values stored in %s\n", argv[2]);

    return 0;
}
