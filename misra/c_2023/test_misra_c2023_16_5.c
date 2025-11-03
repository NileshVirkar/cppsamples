// Test file for MISRA C:2023 Rule 16.5
// A default label shall appear as either the first or the last switch label

// Compliant examples
void compliant_default_position(int x) {
    // Default as first label
    switch (x) {
        default:
            // Handle default
            break;
        case 1:
            // Handle case 1
            break;
        case 2:
            // Handle case 2
            break;
    }
    
    // Default as last label
    switch (x) {
        case 1:
            // Handle case 1
            break;
        case 2:
            // Handle case 2
            break;
        default:
            // Handle default
            break;
    }
}

// Non-compliant examples
void non_compliant_default_position(int x) {
    // Default in the middle
    switch (x) {
        case 1:
            // Handle case 1
            break;
        default: // EMB-ISSUE: [MISRA-C2023-16-5] - Default label not first or last
            // Handle default
            break;
        case 2:
            // Handle case 2
            break;
    }
    
    switch (x) {
        case 10:
            break;
        case 20:
            break;
        default: // EMB-ISSUE: [MISRA-C2023-16-5] - Default label not first or last
            break;
        case 30:
            break;
    }
}

int main(void) {
    compliant_default_position(1);
    non_compliant_default_position(1);
    return 0;
}
