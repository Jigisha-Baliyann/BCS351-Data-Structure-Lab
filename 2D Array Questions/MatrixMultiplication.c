#include <stdio.h>

void multiplyMatrices(int firstMatrix[][3], int secondMatrix[][3], int resultMatrix[][3], int rows1, int cols1, int rows2, int cols2) {
    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        printf("Matrices can't be multiplied!\n");
        return;
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
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
    int firstMatrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int secondMatrix[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMatrix[3][3];

    int rows1 = 3;
    int cols1 = 3;
    int rows2 = 3;
    int cols2 = 3;

    printf("First Matrix:\n");
    displayMatrix(firstMatrix, rows1, cols1);

    printf("\nSecond Matrix:\n");
    displayMatrix(secondMatrix, rows2, cols2);

    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rows1, cols1, rows2, cols2);

    printf("\nResultant Matrix (Product of First and Second Matrix):\n");
    displayMatrix(resultMatrix, rows1, cols2);

    return 0;
}
