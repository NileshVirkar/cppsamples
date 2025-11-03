// Test file for MISRA C:2023 Rule 7.2
// A "u" or "U" suffix shall be applied to all integer constants that are represented in an unsigned type

#include <stdint.h>

// Compliant examples
void compliant_unsigned_literals(void) {
    unsigned int ui1 = 100U;    // OK: U suffix
    unsigned int ui2 = 0xFFU;   // OK: U suffix with hex
    unsigned long ul = 1000UL;  // OK: UL suffix
    
    uint8_t u8 = 0xFFU;        // OK: U suffix
    uint16_t u16 = 65535U;     // OK: U suffix
    uint32_t u32 = 0x12345678U; // OK: U suffix
    
    (void)ui1; (void)ui2; (void)ul;
    (void)u8; (void)u16; (void)u32;
}

// Non-compliant examples
void non_compliant_missing_suffix(void) {
    unsigned int ui1 = 100;     // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    unsigned int ui2 = 0xFF;    // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    unsigned long ul = 1000;    // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    
    uint8_t u8 = 0xFF;         // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    uint16_t u16 = 65535;      // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    uint32_t u32 = 0x12345678; // EMB-ISSUE: [MISRA-C2023-7-2] - Missing U suffix
    
    (void)ui1; (void)ui2; (void)ul;
    (void)u8; (void)u16; (void)u32;
}

void non_compliant_in_expressions(void) {
    unsigned int x = 10 + 20;   // EMB-ISSUE: [MISRA-C2023-7-2] - Both need U
    unsigned int y = 0xFF & 0x0F; // EMB-ISSUE: [MISRA-C2023-7-2] - Both need U
    
    unsigned int mask = 1 << 5; // EMB-ISSUE: [MISRA-C2023-7-2] - Should be 1U
    
    (void)x; (void)y; (void)mask;
}

void non_compliant_arrays(void) {
    unsigned int array[] = {
        1,      // EMB-ISSUE: [MISRA-C2023-7-2]
        2,      // EMB-ISSUE: [MISRA-C2023-7-2]
        3       // EMB-ISSUE: [MISRA-C2023-7-2]
    };
    (void)array;
}

void non_compliant_comparisons(void) {
    unsigned int value = 100U;
    
    if (value > 50) {           // EMB-ISSUE: [MISRA-C2023-7-2] - Should be 50U
        value = 200;            // EMB-ISSUE: [MISRA-C2023-7-2] - Should be 200U
    }
}

int main(void) {
    compliant_unsigned_literals();
    return 0;
}
