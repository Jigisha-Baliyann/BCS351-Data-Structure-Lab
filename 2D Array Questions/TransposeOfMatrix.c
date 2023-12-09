#include <stdio.h>

void transposeMatrix(int matrix[][3], int transpose[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transpose[3][3];

    int rows = 3;
    int cols = 3;

    printf("Original Matrix:\n");
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transpose, rows, cols);

    printf("\nTranspose Matrix:\n");
    displayMatrix(transpose, cols, rows);

    return 0;
}
