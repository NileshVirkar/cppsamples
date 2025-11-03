// Test file for MISRA C:2023 Rule 1.3
// There shall be no occurrence of undefined or critical unspecified behavior

#include <stdint.h>
#include <limits.h>

// Compliant examples
void compliant_behavior(void) {
    int x = 10;
    int y = 2;
    int result = x / y;  // OK: No division by zero
    
    int *p = &x;
    int value = *p;  // OK: Valid pointer dereference
    
    int arr[10];
    arr[5] = 100;  // OK: Within bounds
    
    (void)result;
    (void)value;
}

// Non-compliant examples
void non_compliant_undefined_behavior(void) {
    int x = 10;
    int y = 0;
    int result = x / y;  // EMB-ISSUE: [MISRA-C2023-1-3] - Division by zero (undefined)
    
    int *p = NULL;
    int value = *p;  // EMB-ISSUE: [MISRA-C2023-1-3] - Null pointer dereference (undefined)
    
    int arr[10];
    arr[15] = 100;  // EMB-ISSUE: [MISRA-C2023-1-3] - Array out of bounds (undefined)
    
    // Signed integer overflow
    int max = INT_MAX;
    int overflow = max + 1;  // EMB-ISSUE: [MISRA-C2023-1-3] - Signed overflow (undefined)
    
    // Modifying string literal
    char *str = "Hello";
    str[0] = 'h';  // EMB-ISSUE: [MISRA-C2023-1-3] - Modifying string literal (undefined)
    
    // Uninitialized variable
    int uninitialized;
    int use = uninitialized;  // EMB-ISSUE: [MISRA-C2023-1-3] - Use of uninitialized value
    
    // Multiple modifications without sequence point
    int i = 0;
    i = i++;  // EMB-ISSUE: [MISRA-C2023-1-3] - Undefined evaluation order
    
    (void)result;
    (void)value;
    (void)overflow;
    (void)use;
}

int main(void) {
    compliant_behavior();
    non_compliant_undefined_behavior();
    return 0;
}
