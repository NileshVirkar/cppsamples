// Test file for MISRA C:2023 Rule 12.1
// The precedence of operators within expressions should be made explicit

// Compliant examples
void compliant_explicit_precedence(void) {
    int a = 10, b = 20, c = 30;
    
    int result1 = (a + b) * c;      // OK: Explicit with parentheses
    int result2 = a + (b * c);      // OK: Explicit with parentheses
    int result3 = (a & b) | c;      // OK: Explicit with parentheses
    int result4 = a & (b | c);      // OK: Explicit with parentheses
    
    if ((a > 10) && (b < 30)) {     // OK: Explicit conditions
        result1 = 0;
    }
    
    (void)result1; (void)result2;
    (void)result3; (void)result4;
}

// Non-compliant examples
void non_compliant_implicit_precedence(void) {
    int a = 10, b = 20, c = 30, d = 40;
    
    int result1 = a + b * c;        // EMB-ISSUE: [MISRA-C2023-12-1] - Implicit precedence
    int result2 = a & b | c;        // EMB-ISSUE: [MISRA-C2023-12-1] - Implicit precedence
    int result3 = a << 2 + 1;       // EMB-ISSUE: [MISRA-C2023-12-1] - Implicit precedence
    
    // Complex expression without parentheses
    int result4 = a + b * c - d;    // EMB-ISSUE: [MISRA-C2023-12-1] - Multiple operators
    
    (void)result1; (void)result2;
    (void)result3; (void)result4;
}

void non_compliant_conditions(void) {
    int a = 10, b = 20, c = 30;
    
    if (a > 10 && b < 30) {         // EMB-ISSUE: [MISRA-C2023-12-1] - Implicit precedence
        a = 0;
    }
    
    if (a == 10 || b == 20 && c == 30) {  // EMB-ISSUE: [MISRA-C2023-12-1] - Mixed || and &&
        a = 0;
    }
}

void non_compliant_bitwise(void) {
    unsigned int a = 0xFF;
    unsigned int b = 0x0F;
    unsigned int c = 0xF0;
    
    unsigned int result1 = a & b | c;    // EMB-ISSUE: [MISRA-C2023-12-1] - Bitwise precedence
    unsigned int result2 = a ^ b & c;    // EMB-ISSUE: [MISRA-C2023-12-1] - Mixed bitwise
    unsigned int result3 = a | b ^ c;    // EMB-ISSUE: [MISRA-C2023-12-1] - Mixed bitwise
    
    (void)result1; (void)result2; (void)result3;
}

void non_compliant_shifts(void) {
    int a = 10, b = 2, c = 3;
    
    int result1 = a << b + c;       // EMB-ISSUE: [MISRA-C2023-12-1] - Shift with addition
    int result2 = a >> b - 1;       // EMB-ISSUE: [MISRA-C2023-12-1] - Shift with subtraction
    
    (void)result1; (void)result2;
}

int main(void) {
    compliant_explicit_precedence();
    return 0;
}
