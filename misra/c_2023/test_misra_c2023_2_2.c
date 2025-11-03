// Test file for MISRA C:2023 Rule 2.2
// There shall be no dead code

// Compliant examples
void compliant_code(void) {
    int x = 10;
    int y = 20;
    int result = x + y;  // Used in return
    (void)result;
}

int compliant_function(int a, int b) {
    int temp = a + b;
    return temp;  // All variables used
}

// Non-compliant examples
void non_compliant_unused_assignment(void) {
    int x = 10;
    x = 20;  // EMB-ISSUE: [MISRA-C2023-2-2] - Overwritten without use
    x = 30;
    (void)x;
}

void non_compliant_unused_computation(void) {
    int x = 10;
    int y = 20;
    int unused = x + y;  // EMB-ISSUE: [MISRA-C2023-2-2] - Computed but never used
    x = 30;
    (void)x;
    (void)unused;
}

void non_compliant_unused_parameter(int unused_param) {  // EMB-ISSUE: [MISRA-C2023-2-2]
    int x = 10;
    (void)x;
    // unused_param is never used
}

void non_compliant_write_only(void) {
    int x;
    x = 10;  // EMB-ISSUE: [MISRA-C2023-2-2] - Written but never read
    x = 20;
    (void)x;
}

void non_compliant_ineffective_statement(void) {
    int x = 10;
    x + 5;  // EMB-ISSUE: [MISRA-C2023-2-2] - No effect (dead code)
    (void)x;
}

void non_compliant_redundant_condition(int x) {
    if (x > 0) {
        x = 10;
    }
    if (x > 0) {  // EMB-ISSUE: [MISRA-C2023-2-2] - Redundant check (x always > 0 here)
        x = 20;
    }
    (void)x;
}

int main(void) {
    compliant_code();
    compliant_function(1, 2);
    return 0;
}
