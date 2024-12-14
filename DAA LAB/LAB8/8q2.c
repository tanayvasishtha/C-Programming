/*8.2 Aim of the program: Write a program to find out the Longest Common Subsequence of two
given strings. Calculate length of the LCS.
Input:

Enter the first string into an array: 10010101
Enter the second string into an array: 010110110

Output:
LCS: 100110
LCS Length: 6*/

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", L[m][n]);
}

int main() {
    char X[100], Y[100];
    printf("Enter the first string into an array: ");
    scanf("%s", X);
    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    findLCS(X, Y);

    return 0;
}
#include <stdio.h>  
#include <string.h>

