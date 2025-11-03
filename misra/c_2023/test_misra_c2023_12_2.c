// Test file for MISRA C:2023 Rule 12.2
// The right hand operand of a shift operator shall lie in the range zero to one less than the width in bits

#include <stdint.h>

// Compliant examples
void compliant_shift(void) {
    int x = 1 << 16;  // OK: within range for 32-bit int
    unsigned char c = 1 << 7;  // OK: within range for 8-bit char
    unsigned long long val = 1ULL << 40;  // OK: within range for 64-bit long long
    
    int shift_amount = 10;
    int result = 1 << shift_amount;  // OK: assuming shift_amount is valid
    
    (void)x;
    (void)c;
    (void)val;
    (void)result;
}

// Non-compliant examples
void non_compliant_shift(void) {
    int x = 1 << 32;  // EMB-ISSUE: [MISRA-C2023-12-2] - Shift count >= bit width of int (32)
    int y = 1 << -1;  // EMB-ISSUE: [MISRA-C2023-12-2] - Negative shift count
    unsigned char c = 1 << 8;  // EMB-ISSUE: [MISRA-C2023-12-2] - Shift count >= bit width of char (8)
    
    short s = 1 << 16;  // EMB-ISSUE: [MISRA-C2023-12-2] - Shift count >= bit width of short (16)
    
    // Very large shift on 64-bit type
    unsigned long long big = 1ULL << 64;  // EMB-ISSUE: [MISRA-C2023-12-2] - Shift count >= bit width (64)
    
    (void)x;
    (void)y;
    (void)c;
    (void)s;
    (void)big;
}

int main(void) {
    compliant_shift();
    non_compliant_shift();
    return 0;
}
