// Test file for MISRA C:2023 Rule 9.3
// Arrays shall not be partially initialized

// EMB-ISSUE: Partially initialized array
int arr1[10] = {1, 2, 3};

// EMB-ISSUE: Partial initialization of multidimensional array
int matrix1[3][3] = {{1, 2}, {3}};

// EMB-ISSUE: Character array partially initialized
char str1[20] = "Hello";

struct Point {
    int x, y;
};

// EMB-ISSUE: Struct array partially initialized
struct Point points1[5] = {{1, 2}, {3, 4}};

// EMB-ISSUE: Large array with few initializers
int large_array[100] = {1, 2, 3, 4, 5};

// Compliant: Fully initialized array
int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Compliant: Explicit zero initialization
int arr3[10] = {0};

// Compliant: Complete matrix initialization
int matrix2[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Compliant: Fully initialized character array
char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// Compliant: Complete struct array initialization
struct Point points2[5] = {
    {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}
};

// Compliant: Small array fully initialized
int small[3] = {1, 2, 3};

// EMB-ISSUE: Another partial initialization
float floats[8] = {1.0f, 2.0f};

// Compliant: All zeros
float floats_zero[8] = {0.0f};
