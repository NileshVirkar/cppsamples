// Test file for MISRA C:2023 Rule 2.1
// A project shall not contain unreachable code

// Compliant examples
void compliant_reachable(void) {
    int x = 10;
    if (x > 5) {
        x = 20;
    } else {
        x = 30;
    }
    // All code paths are reachable
}

int compliant_return(int n) {
    if (n > 0) {
        return n;
    } else {
        return 0;
    }
    // No unreachable code after
}

// Non-compliant examples
void non_compliant_after_return(void) {
    int x = 10;
    return;
    x = 20;  // EMB-ISSUE: [MISRA-C2023-2-1] - Unreachable code after return
}

int non_compliant_dead_code(int n) {
    if (n > 0) {
        return n;
    } else {
        return 0;
    }
    return -1;  // EMB-ISSUE: [MISRA-C2023-2-1] - Unreachable return
}

void non_compliant_constant_condition(void) {
    if (0) {  // EMB-ISSUE: [MISRA-C2023-2-1] - Always false
        int x = 10;  // Unreachable
        (void)x;
    }
    
    while (0) {  // EMB-ISSUE: [MISRA-C2023-2-1] - Never executes
        int y = 20;
        (void)y;
    }
}

void non_compliant_after_break(void) {
    for (int i = 0; i < 10; i++) {
        break;
        i++;  // EMB-ISSUE: [MISRA-C2023-2-1] - Unreachable after break
    }
}

void non_compliant_goto_skip(void) {
    goto skip;
    int x = 10;  // EMB-ISSUE: [MISRA-C2023-2-1] - Unreachable code
    (void)x;
skip:
    return;
}

int main(void) {
    compliant_reachable();
    compliant_return(5);
    return 0;
}
