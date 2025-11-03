// Test file for MISRA C:2023 Rule 15.7
// All if ... else if constructs shall be terminated with an else statement

// Compliant examples
void compliant_if_else(int x) {
    if (x == 1) {
        // Handle case 1
    } else if (x == 2) {
        // Handle case 2
    } else if (x == 3) {
        // Handle case 3
    } else {
        // Handle all other cases
    }
    
    // Simple if-else is compliant
    if (x > 0) {
        // Positive
    } else {
        // Non-positive
    }
}

// Non-compliant examples
void non_compliant_if_else(int x) {
    if (x == 1) {
        // Handle case 1
    } else if (x == 2) {
        // Handle case 2
    } else if (x == 3) {
        // Handle case 3
    } // EMB-ISSUE: [MISRA-C2023-15-7] - Missing final else clause
    
    if (x == 10) {
        // Handle 10
    } else if (x == 20) {
        // Handle 20
    } // EMB-ISSUE: [MISRA-C2023-15-7] - Missing final else clause
}

int main(void) {
    compliant_if_else(1);
    non_compliant_if_else(1);
    return 0;
}
