// Test file for MISRA C:2023 Rule 10.4
// Both operands of an operator in which the usual arithmetic conversions are performed shall have the same essential type category

#include <stdint.h>
#include <stdbool.h>

// Compliant examples
void compliant_same_category(void) {
    // Both signed integers
    int x = 10;
    int y = 20;
    int result1 = x + y;        // OK: Both signed int
    
    // Both unsigned integers
    unsigned int ux = 10U;
    unsigned int uy = 20U;
    unsigned int result2 = ux + uy;  // OK: Both unsigned int
    
    // Both floating point
    float f1 = 3.14f;
    float f2 = 2.71f;
    float result3 = f1 + f2;    // OK: Both float
    
    // Same signed type
    int32_t i1 = 100;
    int32_t i2 = 200;
    int32_t result4 = i1 * i2;  // OK: Both int32_t
    
    (void)result1; (void)result2;
    (void)result3; (void)result4;
}

// Non-compliant examples
void non_compliant_mixed_signedness(void) {
    int si = 10;
    unsigned int ui = 20U;
    
    int result1 = si + ui;      // EMB-ISSUE: [MISRA-C2023-10-4] - Mixed signed/unsigned
    int result2 = si - ui;      // EMB-ISSUE: [MISRA-C2023-10-4] - Mixed signed/unsigned
    int result3 = si * ui;      // EMB-ISSUE: [MISRA-C2023-10-4] - Mixed signed/unsigned
    
    (void)result1; (void)result2; (void)result3;
}

void non_compliant_float_int(void) {
    int i = 10;
    float f = 3.14f;
    
    float result1 = i + f;      // EMB-ISSUE: [MISRA-C2023-10-4] - Mixed int/float
    float result2 = f * i;      // EMB-ISSUE: [MISRA-C2023-10-4] - Mixed float/int
    
    (void)result1; (void)result2;
}

void non_compliant_comparisons(void) {
    int si = 10;
    unsigned int ui = 20U;
    
    if (si < ui) {              // EMB-ISSUE: [MISRA-C2023-10-4] - Comparison of mixed types
        si = 0;
    }
    
    float f = 3.14f;
    int i = 3;
    
    if (f > i) {                // EMB-ISSUE: [MISRA-C2023-10-4] - Comparison of float and int
        i = 0;
    }
}

void non_compliant_different_widths(void) {
    int16_t s16 = 100;
    int32_t s32 = 200;
    
    int32_t result = s16 + s32; // Technically same category but different widths
                                // May or may not be flagged depending on implementation
    
    uint8_t u8 = 10U;
    uint16_t u16 = 20U;
    
    uint16_t result2 = u8 + u16; // Different widths but same category
    
    (void)result; (void)result2;
}

void non_compliant_char_int(void) {
    char c = 'A';
    int i = 10;
    
    int result = c + i;         // EMB-ISSUE: [MISRA-C2023-10-4] - char and int
    (void)result;
}

void non_compliant_enum_int(void) {
    enum State { OFF, ON };
    enum State state = ON;
    int value = 10;
    
    int result = state + value; // EMB-ISSUE: [MISRA-C2023-10-4] - enum and int
    (void)result;
}

int main(void) {
    compliant_same_category();
    return 0;
}
