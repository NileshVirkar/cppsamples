// Test file for MISRA C:2023 Rule 13.5
// The right hand operand of a logical && or || operator shall not contain persistent side effects

#include <stdio.h>

int global_counter = 0;

int function_with_side_effect(void) {
    global_counter++;           // Side effect
    return global_counter;
}

int pure_function(int x) {
    return x * 2;               // No side effect
}

// Compliant examples
void compliant_no_side_effects(void) {
    int a = 10, b = 20;
    
    if ((a > 5) && (b < 30)) {      // OK: No side effects
        a = 0;
    }
    
    int x = 100;
    if ((x > 50) || (x < 10)) {     // OK: No side effects
        x = 0;
    }
    
    // Calling pure function is OK
    if ((a > 0) && (pure_function(a) > 10)) {  // OK: No persistent side effects
        a = 0;
    }
}

// Non-compliant examples
void non_compliant_increment_decrement(void) {
    int x = 10, y = 20;
    
    if ((x > 5) && (++y > 10)) {    // EMB-ISSUE: [MISRA-C2023-13-5] - Increment in RHS
        x = 0;
    }
    
    if ((x > 5) || (y-- < 30)) {    // EMB-ISSUE: [MISRA-C2023-13-5] - Decrement in RHS
        x = 0;
    }
}

void non_compliant_function_side_effect(void) {
    int x = 10;
    
    if ((x > 5) && (function_with_side_effect() > 0)) {  // EMB-ISSUE: [MISRA-C2023-13-5]
        x = 0;
    }
    
    if ((x < 100) || (function_with_side_effect() == 10)) {  // EMB-ISSUE: [MISRA-C2023-13-5]
        x = 0;
    }
}

void non_compliant_assignment(void) {
    int x = 10, y = 20, z = 0;
    
    if ((x > 5) && ((z = y) > 10)) { // EMB-ISSUE: [MISRA-C2023-13-5] - Assignment in RHS
        x = 0;
    }
    
    if ((x > 5) || (y = function_with_side_effect())) {  // EMB-ISSUE: [MISRA-C2023-13-5]
        x = 0;
    }
}

void non_compliant_combined(void) {
    int arr[10] = {0};
    int index = 0;
    int value = 5;
    
    // Multiple side effects
    if ((value > 0) && (arr[index++] = value)) {  // EMB-ISSUE: [MISRA-C2023-13-5]
        value = 0;
    }
    
    // Function call with side effect
    if ((index < 10) || (function_with_side_effect() && ++value)) {  // EMB-ISSUE: [MISRA-C2023-13-5]
        index = 0;
    }
}

void non_compliant_nested(void) {
    int a = 10, b = 20, c = 30;
    
    if ((a > 0) && ((b > 0) || (c++))) {  // EMB-ISSUE: [MISRA-C2023-13-5] - Side effect in nested
        a = 0;
    }
}

int main(void) {
    compliant_no_side_effects();
    return 0;
}
