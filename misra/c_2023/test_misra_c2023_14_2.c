// Test file for MISRA C:2023 Rule 14.2
// A for loop shall be well-formed

#include <stdint.h>

// Compliant examples
void compliant_well_formed_loops(void) {
    // Standard for loop
    for (int i = 0; i < 10; i++) {      // OK: Well-formed
        // loop body
    }
    
    // Loop with explicit initialization
    int j;
    for (j = 0; j < 20; j++) {          // OK: Well-formed
        // loop body
    }
    
    // Multiple counters (if properly managed)
    for (int i = 0, j = 10; i < j; i++, j--) {  // OK: Both controlled
        // loop body
    }
}

// Non-compliant examples
void non_compliant_malformed_loops(void) {
    int i;
    
    // Empty initialization
    for (; i < 10; i++) {               // EMB-ISSUE: [MISRA-C2023-14-2] - No initialization
        // loop body
    }
    
    // Empty condition
    i = 0;
    for (i = 0; ; i++) {                // EMB-ISSUE: [MISRA-C2023-14-2] - No condition
        if (i >= 10) break;
    }
    
    // Empty increment
    for (i = 0; i < 10; ) {             // EMB-ISSUE: [MISRA-C2023-14-2] - No increment
        i++;
    }
    
    // Completely empty
    for (;;) {                          // EMB-ISSUE: [MISRA-C2023-14-2] - All parts empty
        break;
    }
}

void non_compliant_counter_modification(void) {
    // Counter modified in body
    for (int i = 0; i < 10; i++) {
        i += 2;                         // EMB-ISSUE: [MISRA-C2023-14-2] - Counter modified in body
    }
    
    // Counter modified by function
    int j;
    for (j = 0; j < 10; j++) {
        modify_counter(&j);             // EMB-ISSUE: [MISRA-C2023-14-2] - Counter modified elsewhere
    }
}

void modify_counter(int *counter) {
    (*counter)++;
}

void non_compliant_floating_modification(void) {
    int i;
    int limit = 10;
    
    // Loop limit modified in body
    for (i = 0; i < limit; i++) {
        limit++;                        // EMB-ISSUE: [MISRA-C2023-14-2] - Limit modified
    }
}

void non_compliant_multiple_variables(void) {
    int i, j, k;
    
    // Unrelated variables in initialization
    for (i = 0, j = 10, k = 20; i < 10; i++) {  // EMB-ISSUE: [MISRA-C2023-14-2] - k not used
        j--;
    }
}

void non_compliant_complex_increment(void) {
    int arr[10];
    int i, j = 0;
    
    // Complex increment expression
    for (i = 0; i < 10; i++, j++, arr[j] = i) {  // EMB-ISSUE: [MISRA-C2023-14-2] - Side effects
        // loop body
    }
}

int main(void) {
    compliant_well_formed_loops();
    return 0;
}
