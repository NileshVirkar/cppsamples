// Test file for MISRA C:2023 Rule 13.1
// Initializer lists shall not contain persistent side effects

#include <stdio.h>

int counter = 0;

int get_value(void) {
    return counter++;  // Function with side effect
}

int pure_function(int x) {
    return x * 2;  // No side effects (pure function)
}

// Compliant examples
void compliant_initializers(void) {
    // Constants and literals - no side effects
    int arr1[] = {1, 2, 3, 4, 5};
    
    const int VALUE1 = 10;
    const int VALUE2 = 20;
    int arr2[] = {VALUE1, VALUE2, 30};
    
    // Struct with literal values
    struct Point {
        int x;
        int y;
    };
    
    struct Point p1 = {10, 20};  // OK: No side effects
    
    // Pure expressions without side effects
    int a = 5;
    int arr3[] = {a, a + 1, a * 2};  // OK: No persistent side effects
}

// Non-compliant examples
void non_compliant_initializers(void) {
    // Function call with side effects in initializer
    int arr1[] = {
        get_value(),  // EMB-ISSUE: [MISRA-C2023-13-1] - Function call with side effect
        get_value(),  // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect
        get_value()   // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect
    };
    
    // Increment/decrement operators
    int x = 0;
    int arr2[] = {
        x++,  // EMB-ISSUE: [MISRA-C2023-13-1] - Increment in initializer
        ++x,  // EMB-ISSUE: [MISRA-C2023-13-1] - Increment in initializer
        x     // Order-dependent
    };
    
    // Assignment in initializer
    int y = 5;
    int arr3[] = {
        y = 10,  // EMB-ISSUE: [MISRA-C2023-13-1] - Assignment in initializer
        y = 20,  // EMB-ISSUE: [MISRA-C2023-13-1] - Assignment in initializer
        y
    };
    
    // Struct with side effects
    struct Point {
        int x;
        int y;
    };
    
    int coord = 0;
    struct Point p = {
        coord++,  // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect in initializer
        coord++   // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect in initializer
    };
    
    // Mixed side effects
    int arr4[] = {
        counter,      // OK by itself
        counter++,    // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect
        get_value()   // EMB-ISSUE: [MISRA-C2023-13-1] - Side effect
    };
}

int main(void) {
    compliant_initializers();
    non_compliant_initializers();
    return 0;
}
