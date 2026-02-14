// Write a program to check whether a given square matrix is an Identity Matrix.
// An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1; // assume true initially

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            else if (i != j && matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}