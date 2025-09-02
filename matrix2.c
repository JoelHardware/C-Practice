#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the matrix

int main() {
    int matrix[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j;
    int sum = 0, largest;
    int isSymmetric = 1;

    // Input the dimensions of the matrix
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    // Validate dimensions
    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Input the matrix elements
    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute the transpose and other calculations
    largest = matrix[0][0]; // Initialize largest element

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // Transpose: Swap rows and columns
            transpose[j][i] = matrix[i][j];

            // Calculate sum
            sum += matrix[i][j];

            // Find largest element
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }

            // Check symmetry
            if (rows == cols && matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
            }
        }
    }

    // Output the original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Output the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Output the results
    printf("\nSum of all elements: %d\n", sum);
    printf("Largest element in the matrix: %d\n", largest);

    if (rows == cols) {
        printf("The matrix is %ssymmetric.\n", isSymmetric ? "" : "not ");
    } else {
        printf("The matrix is not symmetric (not square).\n");
    }

    return 0;
}
