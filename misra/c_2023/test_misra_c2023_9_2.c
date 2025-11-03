// Test file for MISRA C:2023 Rule 9.2
// The initializer for an aggregate or union shall be enclosed in braces

#include <stdint.h>

// Compliant examples
void compliant_arrays(void) {
    int arr1[] = {1, 2, 3};         // OK: Braces used
    int arr2[5] = {0};              // OK: Braces used
    int arr3[3] = {1, 2, 3};        // OK: Braces used
    
    (void)arr1; (void)arr2; (void)arr3;
}

void compliant_structs(void) {
    struct Point {
        int x;
        int y;
    };
    
    struct Point p1 = {10, 20};     // OK: Braces used
    struct Point p2 = {.x = 5, .y = 10};  // OK: Designated initializers
    
    (void)p1; (void)p2;
}

void compliant_nested(void) {
    int matrix[2][3] = {
        {1, 2, 3},                  // OK: Nested braces
        {4, 5, 6}
    };
    
    struct Data {
        int arr[3];
        int value;
    };
    
    struct Data d = {
        {1, 2, 3},                  // OK: Braces for array member
        10
    };
    
    (void)matrix; (void)d;
}

// Non-compliant examples
void non_compliant_missing_braces(void) {
    // Note: Some compilers accept these with warnings
    
    int arr1[3] = 1, 2, 3;          // EMB-ISSUE: [MISRA-C2023-9-2] - Missing outer braces
    
    int matrix[2][2] = {1, 2, 3, 4}; // EMB-ISSUE: [MISRA-C2023-9-2] - Missing inner braces
    
    struct Point {
        int x;
        int y;
    };
    
    struct Point p = 10, 20;        // EMB-ISSUE: [MISRA-C2023-9-2] - Missing braces
    
    (void)arr1; (void)matrix; (void)p;
}

void non_compliant_nested_missing(void) {
    int matrix[2][3] = {
        1, 2, 3,                    // EMB-ISSUE: [MISRA-C2023-9-2] - Missing braces for sub-array
        4, 5, 6
    };
    
    struct Data {
        int arr[3];
        int value;
    };
    
    struct Data d = {
        1, 2, 3,                    // EMB-ISSUE: [MISRA-C2023-9-2] - Missing braces for array member
        10
    };
    
    (void)matrix; (void)d;
}

union U {
    int i;
    float f;
};

void non_compliant_union(void) {
    union U u1 = 10;                // EMB-ISSUE: [MISRA-C2023-9-2] - Missing braces
    union U u2 = {10};              // OK: Has braces
    
    (void)u1; (void)u2;
}

int main(void) {
    compliant_arrays();
    return 0;
}
