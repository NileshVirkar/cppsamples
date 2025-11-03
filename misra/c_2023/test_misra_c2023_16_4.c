// Test file for MISRA C:2023 Rule 16.4
// Every switch statement shall have a default label

// Compliant examples
void compliant_switch_default(int x) {
    switch (x) {
        case 1:
            // Handle case 1
            break;
        case 2:
            // Handle case 2
            break;
        default:
            // Handle unexpected values
            break;
    }
    
    switch (x) {
        case 10:
            break;
        case 20:
            break;
        case 30:
            break;
        default:
            // Empty default is OK
            break;
    }
}

// Non-compliant examples
void non_compliant_switch_default(int x) {
    switch (x) { // EMB-ISSUE: [MISRA-C2023-16-4] - Missing default label
        case 1:
            // Handle case 1
            break;
        case 2:
            // Handle case 2
            break;
    }
    
    switch (x) { // EMB-ISSUE: [MISRA-C2023-16-4] - Missing default label
        case 10:
            break;
        case 20:
            break;
        case 30:
            break;
    }
}

int main(void) {
    compliant_switch_default(1);
    non_compliant_switch_default(1);
    return 0;
}
