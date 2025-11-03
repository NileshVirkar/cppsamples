// Test file for MISRA C:2023 Rule 16.1
// All switch statements shall be well-formed

// Compliant examples
void compliant_switch(int value) {
    // Well-formed switch with all required elements
    switch (value) {
        case 0:
            // Handle case 0
            break;
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

void compliant_with_compound(int value) {
    switch (value) {
        case 0: {
            int local = 10;
            (void)local;
            break;
        }
        case 1: {
            int local = 20;
            (void)local;
            break;
        }
        default: {
            break;
        }
    }
}

// Non-compliant examples
void non_compliant_missing_default(int value) {
    switch (value) {                // EMB-ISSUE: [MISRA-C2023-16-1] - Missing default
        case 0:
            break;
        case 1:
            break;
    }
}

void non_compliant_missing_breaks(int value) {
    switch (value) {
        case 0:
            value = 10;             // EMB-ISSUE: [MISRA-C2023-16-1] - Missing break (fall-through)
        case 1:
            value = 20;             // EMB-ISSUE: [MISRA-C2023-16-1] - Missing break
        case 2:
            value = 30;
            break;
        default:
            break;
    }
}

void non_compliant_empty_cases(int value) {
    switch (value) {
        case 0:                     // EMB-ISSUE: [MISRA-C2023-16-1] - Empty case
        case 1:
            value = 10;
            break;
        case 2:                     // EMB-ISSUE: [MISRA-C2023-16-1] - Empty case
        default:
            value = 20;
            break;
    }
}

void non_compliant_statements_before_case(int value) {
    switch (value) {
        int x = 10;                 // EMB-ISSUE: [MISRA-C2023-16-1] - Statement before first case
        (void)x;
        case 0:
            break;
        default:
            break;
    }
}

void non_compliant_nested_label(int value) {
    switch (value) {
        case 0:
            if (value == 0) {
        case 1:                     // EMB-ISSUE: [MISRA-C2023-16-1] - case inside if block
                value = 10;
            }
            break;
        default:
            break;
    }
}

void non_compliant_default_not_last(int value) {
    switch (value) {
        default:                    // EMB-ISSUE: [MISRA-C2023-16-1] - default not last
            value = 0;
            break;
        case 0:
            value = 10;
            break;
        case 1:
            value = 20;
            break;
    }
}

void non_compliant_empty_switch(int value) {
    switch (value) {                // EMB-ISSUE: [MISRA-C2023-16-1] - Empty switch
    }
}

int main(void) {
    compliant_switch(1);
    return 0;
}
