// Test file for MISRA C:2023 Rule 14.1
// A loop counter shall not have essentially floating type

#include <stdint.h>

// Compliant examples
void compliant_integer_counters(void) {
    // Integer loop counters
    for (int i = 0; i < 10; i++) {          // OK: int counter
        // loop body
    }
    
    for (unsigned int u = 0U; u < 100U; u++) {  // OK: unsigned int counter
        // loop body
    }
    
    for (size_t s = 0; s < 50; s++) {      // OK: size_t counter
        // loop body
    }
    
    int32_t count;
    for (count = 0; count < 20; count++) { // OK: int32_t counter
        // loop body
    }
}

// Non-compliant examples
void non_compliant_float_counters(void) {
    // Float loop counter
    for (float f = 0.0f; f < 10.0f; f += 1.0f) {  // EMB-ISSUE: [MISRA-C2023-14-1]
        // loop body
    }
    
    // Double loop counter
    for (double d = 0.0; d < 100.0; d += 0.5) {   // EMB-ISSUE: [MISRA-C2023-14-1]
        // loop body
    }
    
    // Long double loop counter
    for (long double ld = 0.0L; ld < 50.0L; ld++) {  // EMB-ISSUE: [MISRA-C2023-14-1]
        // loop body
    }
}

void non_compliant_float_increment(void) {
    float f;
    for (f = 0.0f; f < 10.0f; f = f + 0.1f) {  // EMB-ISSUE: [MISRA-C2023-14-1]
        // Precision issues with floating point
    }
}

void non_compliant_while_float(void) {
    float x = 0.0f;
    while (x < 10.0f) {             // EMB-ISSUE: [MISRA-C2023-14-1] - Float used as loop control
        // loop body
        x += 0.5f;
    }
    
    double d = 1.0;
    do {
        d *= 1.1;
    } while (d < 100.0);            // EMB-ISSUE: [MISRA-C2023-14-1] - Double used as loop control
}

void non_compliant_comparison_issues(void) {
    // Floating point comparison in loop can be problematic
    for (float f = 0.0f; f != 10.0f; f += 0.1f) {  // EMB-ISSUE: [MISRA-C2023-14-1]
        // May never terminate due to precision issues
    }
}

int main(void) {
    compliant_integer_counters();
    return 0;
}
