#include <stdio.h>

void addMatrices(int firstMatrix[][3], int secondMatrix[][3], int resultMatrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
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

    int rows = 3;
    int cols = 3;

    printf("First Matrix:\n");
    displayMatrix(firstMatrix, rows, cols);

    printf("\nSecond Matrix:\n");
    displayMatrix(secondMatrix, rows, cols);

    addMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);

    printf("\nResultant Matrix (Sum of First and Second Matrix):\n");
    displayMatrix(resultMatrix, rows, cols);

    return 0;
}
