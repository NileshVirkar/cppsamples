// Test file for MISRA C:2023 Rule 16.3
// An unconditional break statement shall terminate every switch-clause

// Compliant examples
void compliant_switch(int x) {
    switch (x) {
        case 1:
            // Do something
            break;
        case 2:
            // Do something else
            break;
        case 3:
            return;  // OK: return is also a valid terminator
        default:
            // Default case
            break;
    }
}

// Non-compliant examples
void non_compliant_switch(int x) {
    switch (x) {
        case 1:
            // Do something
            // EMB-ISSUE: [MISRA-C2023-16-3] - Missing break statement
        case 2:
            // Fall-through from case 1
            break;
        case 3:
            // Do something
            // EMB-ISSUE: [MISRA-C2023-16-3] - Missing break statement
        default:
            // Default case
            break;
    }
    
    switch (x) {
        case 10:
            // Another case
            // EMB-ISSUE: [MISRA-C2023-16-3] - Missing break statement
        case 20:
            break;
        default:
            break;
    }
}

int main(void) {
    compliant_switch(1);
    non_compliant_switch(1);
    return 0;
}
