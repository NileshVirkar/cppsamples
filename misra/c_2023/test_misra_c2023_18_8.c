// Test file for MISRA C:2023 Rule 18.8
// Variable-length array types shall not be used

#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_MATRIX_SIZE 100

// Compliant examples
void compliant_arrays(void) {
    // Fixed-size arrays
    int buffer[MAX_BUFFER_SIZE];  // OK: Fixed size
    char string[256];             // OK: Fixed size
    
    // Multi-dimensional fixed arrays
    int matrix[10][10];           // OK: Fixed size
    
    // Using const for size (still fixed)
    const int SIZE = 50;
    int array[50];  // OK: Constant expression
    
    (void)buffer;
    (void)string;
    (void)matrix;
    (void)array;
}

void compliant_dynamic_allocation(int n) {
    // Dynamic allocation with error checking
    int *buffer = (int*)malloc(n * sizeof(int));
    if (buffer == NULL) {
        return;  // Handle allocation failure
    }
    
    // Use buffer...
    
    free(buffer);
}

// Non-compliant examples - Variable Length Arrays
void non_compliant_vla(int n, int m) {
    // Simple VLA
    int buffer[n];  // EMB-ISSUE: [MISRA-C2023-18-8] - Variable-length array
    
    // VLA in different contexts
    char string[n + 10];  // EMB-ISSUE: [MISRA-C2023-18-8] - VLA with expression
    
    // Multi-dimensional VLA
    int matrix[n][m];  // EMB-ISSUE: [MISRA-C2023-18-8] - 2D VLA
    
    // VLA with calculation
    int array[n * 2];  // EMB-ISSUE: [MISRA-C2023-18-8] - VLA with expression
    
    // Partially variable array
    int mixed[10][n];  // EMB-ISSUE: [MISRA-C2023-18-8] - VLA in second dimension
    
    (void)buffer;
    (void)string;
    (void)matrix;
    (void)array;
    (void)mixed;
}

void non_compliant_vla_parameters(int size) {
    // VLA based on parameter
    int data[size];  // EMB-ISSUE: [MISRA-C2023-18-8] - VLA
    
    int length = size * 2;
    int extended[length];  // EMB-ISSUE: [MISRA-C2023-18-8] - VLA
    
    (void)data;
    (void)extended;
}

void non_compliant_vla_2d(int rows, int cols) {
    // 2D VLA
    double matrix[rows][cols];  // EMB-ISSUE: [MISRA-C2023-18-8] - 2D VLA
    
    // 3D VLA
    int cube[rows][cols][rows];  // EMB-ISSUE: [MISRA-C2023-18-8] - 3D VLA
    
    (void)matrix;
    (void)cube;
}

int main(void) {
    compliant_arrays();
    compliant_dynamic_allocation(100);
    non_compliant_vla(50, 50);
    non_compliant_vla_parameters(200);
    non_compliant_vla_2d(10, 20);
    return 0;
}
