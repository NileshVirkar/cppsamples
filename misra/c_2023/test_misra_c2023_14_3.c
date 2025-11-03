// Test file for MISRA C:2023 Rule 14.3
// Controlling expressions shall not be invariant

#include <stdbool.h>

#define CONSTANT_TRUE 1
#define CONSTANT_FALSE 0

// Compliant examples
void compliant_variable_conditions(void) {
    int value = 10;
    
    if (value > 5) {                // OK: Variable condition
        value = 0;
    }
    
    while (value < 100) {           // OK: Variable condition
        value++;
    }
    
    for (int i = 0; i < 10; i++) {  // OK: Variable condition
        // loop body
    }
}

void compliant_function_result(int param) {
    if (param != 0) {               // OK: Parameter can vary
        param = 0;
    }
    
    while (get_status()) {          // OK: Function return can vary
        // loop body
    }
}

int get_status(void) {
    static int counter = 0;
    return counter++ < 10;
}

// Non-compliant examples
void non_compliant_constant_conditions(void) {
    int x = 10;
    
    if (1) {                        // EMB-ISSUE: [MISRA-C2023-14-3] - Always true
        x = 20;
    }
    
    if (0) {                        // EMB-ISSUE: [MISRA-C2023-14-3] - Always false (dead code)
        x = 30;
    }
    
    if (CONSTANT_TRUE) {            // EMB-ISSUE: [MISRA-C2023-14-3] - Constant macro
        x = 40;
    }
    
    (void)x;
}

void non_compliant_constant_loops(void) {
    int count = 0;
    
    while (1) {                     // EMB-ISSUE: [MISRA-C2023-14-3] - Infinite loop (invariant)
        if (count++ > 100) break;
    }
    
    while (0) {                     // EMB-ISSUE: [MISRA-C2023-14-3] - Never executes
        count++;
    }
    
    do {
        count++;
    } while (0);                    // EMB-ISSUE: [MISRA-C2023-14-3] - Always executes once only
}

void non_compliant_tautology(void) {
    int x = 10;
    
    if (x || !x) {                  // EMB-ISSUE: [MISRA-C2023-14-3] - Always true (tautology)
        x = 0;
    }
    
    if (x && !x) {                  // EMB-ISSUE: [MISRA-C2023-14-3] - Always false (contradiction)
        x = 0;
    }
}

void non_compliant_self_comparison(void) {
    int value = 100;
    
    if (value == value) {           // EMB-ISSUE: [MISRA-C2023-14-3] - Always true
        value = 0;
    }
    
    if (value != value) {           // EMB-ISSUE: [MISRA-C2023-14-3] - Always false
        value = 0;
    }
}

void non_compliant_constant_expressions(void) {
    if (5 > 3) {                    // EMB-ISSUE: [MISRA-C2023-14-3] - Constant expression
        int x = 10;
        (void)x;
    }
    
    if (sizeof(int) == 0) {         // EMB-ISSUE: [MISRA-C2023-14-3] - Always false
        int y = 20;
        (void)y;
    }
}

void non_compliant_for_loop(void) {
    for (int i = 0; 1; i++) {       // EMB-ISSUE: [MISRA-C2023-14-3] - Invariant condition
        if (i >= 10) break;
    }
    
    for (int i = 0; 0; i++) {       // EMB-ISSUE: [MISRA-C2023-14-3] - Never executes
        // dead code
    }
}

int main(void) {
    compliant_variable_conditions();
    return 0;
}
