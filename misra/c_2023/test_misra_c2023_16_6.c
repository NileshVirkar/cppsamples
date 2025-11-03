// Test file for MISRA C:2023 Rule 16.6
// Every switch statement shall have at least two switch-clauses

// Compliant examples
void compliant_min_cases(int x) {
    // Two case labels (not counting default)
    switch (x) {
        case 1:
            // Handle case 1
            break;
        case 2:
            // Handle case 2
            break;
        default:
            break;
    }
    
    // Multiple cases
    switch (x) {
        case 10:
            break;
        case 20:
            break;
        case 30:
            break;
        default:
            break;
    }
}

// Non-compliant examples
void non_compliant_min_cases(int x) {
    // Only one case label
    switch (x) { // EMB-ISSUE: [MISRA-C2023-16-6] - Only one case label
        case 1:
            // Handle case 1
            break;
        default:
            break;
    }
    
    // Only default, no case labels
    switch (x) { // EMB-ISSUE: [MISRA-C2023-16-6] - No case labels
        default:
            // Only default
            break;
    }
    
    // Should use if statement instead
    switch (x) { // EMB-ISSUE: [MISRA-C2023-16-6] - Only one case label
        case 42:
            break;
        default:
            break;
    }
}

int main(void) {
    compliant_min_cases(1);
    non_compliant_min_cases(1);
    return 0;
}
