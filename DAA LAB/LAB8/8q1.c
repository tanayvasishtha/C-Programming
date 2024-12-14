/*8.1 Aim of the program: Write a program to implement the matrix chain multiplication problem
using M-table & S-table to find optimal parenthesization of a matrix-chain product. Print the
number of scalar multiplications required for the given input.
Note# Dimensions of the matrices can be inputted as row and column values. Validate the
dimension compatibility.
Input:
Enter number of matrices: 4
Enter row and col size of A1: 30 35
Enter row and col size of A2: 35 15
Enter row and col size of A3: 15 5
Enter row and col size of A4: 5 10
Output:
M Table:
0 15750 7875 9375
0 0 2625 4375
0 0 0 750
0 0 0 0
S Table:
0 1 1 3
0 0 2 3
0 0 0 3
0 0 0 0
Optimal parenthesization: ( ( A1 (A2 A3)) A4)
The optimal ordering of the given matrices requires 9375 scalar multiplications.*/

#include <stdio.h>
#include <limits.h>

void printOptimalParens(int s[][10], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[10][10], s[10][10];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i <= j)
                printf("%d ", m[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i <= j)
                printf("%d ", s[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n - 1]);
}

int main() {
    int n, i;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[10];
    for (i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &p[i], &p[i + 1]);
    }

    matrixChainOrder(p, n + 1);

    return 0;
}