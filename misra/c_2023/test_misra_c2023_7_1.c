// Test file for MISRA C:2023 Rule 7.1
// Octal constants shall not be used

// Compliant examples
void compliant_constants(void) {
    int decimal = 100;          // OK: Decimal
    int hex = 0x64;             // OK: Hexadecimal
    int binary = 0b1100100;     // OK: Binary (C23)
    
    int array[] = {10, 20, 30}; // OK: All decimal
    
    (void)decimal;
    (void)hex;
    (void)binary;
}

// Non-compliant examples
void non_compliant_octal(void) {
    int octal1 = 0100;          // EMB-ISSUE: [MISRA-C2023-7-1] - Octal constant
    int octal2 = 0777;          // EMB-ISSUE: [MISRA-C2023-7-1] - Octal constant
    int octal3 = 052;           // EMB-ISSUE: [MISRA-C2023-7-1] - Octal constant
    
    int array[] = {
        10,
        020,                    // EMB-ISSUE: [MISRA-C2023-7-1] - Octal in array
        30
    };
    
    // Misleading - looks decimal but is octal
    int permissions = 0644;     // EMB-ISSUE: [MISRA-C2023-7-1] - Octal
    
    // Long octal
    long octal_long = 01234567L; // EMB-ISSUE: [MISRA-C2023-7-1]
    
    (void)octal1;
    (void)octal2;
    (void)octal3;
    (void)array;
    (void)permissions;
    (void)octal_long;
}

void non_compliant_in_expressions(void) {
    int x = 10 + 077;           // EMB-ISSUE: [MISRA-C2023-7-1]
    int y = 0123 * 2;           // EMB-ISSUE: [MISRA-C2023-7-1]
    
    if (x > 0100) {             // EMB-ISSUE: [MISRA-C2023-7-1]
        y = 0;
    }
    
    (void)y;
}

int main(void) {
    compliant_constants();
    return 0;
}
