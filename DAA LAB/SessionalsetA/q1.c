//write a program in C to copy special characters of file f1.txt to f2.txt and display content of f2.txt
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *f1, *f2;
    char ch;
    int specialCount = 0;
    
    f1 = fopen("f1.txt", "r");
    if (f1 == NULL) {
        printf("Error opening source file f1.txt\n");
        return 1;
    }
    
    f2 = fopen("f2.txt", "w");
    if (f2 == NULL) {
        printf("Error opening destination file f2.txt\n");
        fclose(f1);
        return 1;
    }
    
    
    while ((ch = fgetc(f1)) != EOF) {
    
        if (!isalnum(ch) && !isspace(ch)) {
            fputc(ch, f2);
            specialCount++;
        }
    }
    
    fclose(f1);
    fclose(f2);
    
    printf("Special characters copied: %d\n", specialCount);
    
    f2 = fopen("f2.txt", "r");
    if (f2 == NULL) {
        printf("Error opening f2.txt for reading\n");
        return 1;
    }
    
    printf("\nContents of f2.txt:\n");
    while ((ch = fgetc(f2)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    
    fclose(f2);
    return 0;
}