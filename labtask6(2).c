#include <stdio.h>

// Function to add two matrices
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to multiply two matrices using Strassen’s Algorithm
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;
    int A_result[2][2], B_result[2][2];

    // M1 = (A11 + A22) * (B11 + B22)
    add(A, (int[2][2]){{A[1][1], 0}, {0, A[1][1]}}, A_result);
    add(B, (int[2][2]){{B[1][1], 0}, {0, B[1][1]}}, B_result);
    M1 = A_result[0][0] * B_result[0][0];

    // M2 = (A21 + A22) * B11
    A_result[0][0] = A[1][0] + A[1][1];
    M2 = A_result[0][0] * B[0][0];

    // M3 = A11 * (B12 - B22)
    B_result[0][0] = B[0][1] - B[1][1];
    M3 = A[0][0] * B_result[0][0];

    // M4 = A22 * (B21 - B11)
    B_result[0][0] = B[1][0] - B[0][0];
    M4 = A[1][1] * B_result[0][0];

    // M5 = (A11 + A12) * B22
    A_result[0][0] = A[0][0] + A[0][1];
    M5 = A_result[0][0] * B[1][1];

    // M6 = (A21 - A11) * (B11 + B12)
    A_result[0][0] = A[1][0] - A[0][0];
    B_result[0][0] = B[0][0] + B[0][1];
    M6 = A_result[0][0] * B_result[0][0];

    // M7 = (A12 - A22) * (B21 + B22)
    A_result[0][0] = A[0][1] - A[1][1];
    B_result[0][0] = B[1][0] + B[1][1];
    M7 = A_result[0][0] * B_result[0][0];

    // Calculating C matrix
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

// Driver code
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassen(A, B, C);

    printf("Resultant Matrix using Strassen's Algorithm:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
