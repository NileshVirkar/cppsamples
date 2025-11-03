// Test file for MISRA C:2023 Rule 15.6
// The body of an iteration-statement or a selection-statement shall be a compound-statement

// Compliant examples
void compliant_compound_statements(void) {
    int x = 10;
    
    // if with compound statement
    if (x > 5) {                    // OK: Compound statement
        x = 20;
    }
    
    // if-else with compound statements
    if (x > 15) {                   // OK: Both compound
        x = 30;
    } else {
        x = 10;
    }
    
    // while with compound statement
    while (x > 0) {                 // OK: Compound statement
        x--;
    }
    
    // for with compound statement
    for (int i = 0; i < 10; i++) {  // OK: Compound statement
        x += i;
    }
    
    // do-while with compound statement
    do {                            // OK: Compound statement
        x++;
    } while (x < 20);
}

// Non-compliant examples
void non_compliant_single_statements(void) {
    int x = 10;
    
    // if without braces
    if (x > 5)                      // EMB-ISSUE: [MISRA-C2023-15-6] - No compound statement
        x = 20;
    
    // if-else without braces
    if (x > 15)                     // EMB-ISSUE: [MISRA-C2023-15-6]
        x = 30;
    else                            // EMB-ISSUE: [MISRA-C2023-15-6]
        x = 10;
    
    // while without braces
    while (x > 0)                   // EMB-ISSUE: [MISRA-C2023-15-6]
        x--;
    
    // for without braces
    for (int i = 0; i < 10; i++)    // EMB-ISSUE: [MISRA-C2023-15-6]
        x += i;
    
    // do-while without braces
    do                              // EMB-ISSUE: [MISRA-C2023-15-6]
        x++;
    while (x < 20);
}

void non_compliant_nested(void) {
    int x = 10, y = 20;
    
    // Nested if without braces
    if (x > 5)                      // EMB-ISSUE: [MISRA-C2023-15-6]
        if (y > 15)                 // EMB-ISSUE: [MISRA-C2023-15-6]
            x = y;
    
    // Partially braced
    if (x > 5) {                    // OK for outer
        if (y > 15)                 // EMB-ISSUE: [MISRA-C2023-15-6] - Inner not braced
            x = y;
    }
    
    // Loop in if without braces
    if (x > 0)                      // EMB-ISSUE: [MISRA-C2023-15-6]
        while (x > 0)               // EMB-ISSUE: [MISRA-C2023-15-6]
            x--;
}

void non_compliant_empty_statements(void) {
    int x = 10;
    
    // Empty statement (still needs braces for clarity)
    if (x > 5)                      // EMB-ISSUE: [MISRA-C2023-15-6]
        ;  // Empty statement
    
    while (x > 0)                   // EMB-ISSUE: [MISRA-C2023-15-6]
        ;  // Empty body
}

void non_compliant_multiline_single(void) {
    int x = 10, y = 20, z = 30;
    
    // Single statement split across lines (still needs braces)
    if (x > 5)                      // EMB-ISSUE: [MISRA-C2023-15-6]
        x = y +
            z;
}

int main(void) {
    compliant_compound_statements();
    return 0;
}
