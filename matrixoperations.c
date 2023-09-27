#include <stdio.h>

// Function to add two matrices
void matrixAddition(int A[][3], int B[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply two matrices
void matrixMultiplication(int A[][3], int B[][3], int result[][3], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void matrixTranspose(int A[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = A[j][i];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    printf("Matrix A:\n");
    displayMatrix(A, 3, 3);

    printf("Matrix B:\n");
    displayMatrix(B, 3, 3);

    // Perform matrix addition
    matrixAddition(A, B, result, 3, 3);
    printf("Matrix A + B:\n");
    displayMatrix(result, 3, 3);

    // Perform matrix multiplication
    matrixMultiplication(A, B, result, 3, 3, 3);
    printf("Matrix A * B:\n");
    displayMatrix(result, 3, 3);

    // Perform matrix transpose on matrix A
    matrixTranspose(A, result, 3, 3);
    printf("Transpose of Matrix A:\n");
    displayMatrix(result, 3, 3);

    return 0;
}
