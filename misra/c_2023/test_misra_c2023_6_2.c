// Test file for MISRA C:2023 Rule 6.2
// Single-bit named bit fields shall not be of a signed type

#include <stdint.h>
#include <stdbool.h>

// Compliant examples
struct CompliantFlags {
    unsigned int flag1 : 1;     // OK: unsigned single bit
    unsigned int flag2 : 1;     // OK: unsigned single bit
    _Bool enabled : 1;          // OK: _Bool for single bit
    unsigned int status : 2;    // OK: multi-bit can be unsigned
    signed int value : 3;       // OK: multi-bit signed is allowed
};

struct CompliantSingleBit {
    unsigned int ready : 1;     // OK
    unsigned int busy : 1;      // OK
    uint8_t active : 1;        // OK: explicitly unsigned
};

// Non-compliant examples
struct NonCompliantSingleBit {
    signed int flag : 1;        // EMB-ISSUE: [MISRA-C2023-6-2] - Signed single-bit
    int status : 1;             // EMB-ISSUE: [MISRA-C2023-6-2] - Plain int single-bit (implementation-defined)
};

struct NonCompliantMixed {
    unsigned int good_flag : 1; // OK
    signed int bad_flag : 1;    // EMB-ISSUE: [MISRA-C2023-6-2] - Signed single-bit
    int another_bad : 1;        // EMB-ISSUE: [MISRA-C2023-6-2] - Plain int single-bit
    signed int multi : 3;       // OK: multi-bit signed allowed
};

struct NonCompliantSigned {
    signed int bit0 : 1;        // EMB-ISSUE: [MISRA-C2023-6-2]
    signed int bit1 : 1;        // EMB-ISSUE: [MISRA-C2023-6-2]
    signed int bit2 : 1;        // EMB-ISSUE: [MISRA-C2023-6-2]
};

struct NonCompliantPlainInt {
    int flag_a : 1;             // EMB-ISSUE: [MISRA-C2023-6-2]
    int flag_b : 1;             // EMB-ISSUE: [MISRA-C2023-6-2]
    int counter : 4;            // OK: multi-bit
};

// Problematic single-bit signed (can only be 0 or -1)
struct ProblematicSigned {
    signed int error : 1;       // EMB-ISSUE: [MISRA-C2023-6-2] - Only -1 or 0
};

int main(void) {
    struct CompliantFlags cf;
    struct NonCompliantSingleBit ncf;
    
    cf.flag1 = 1;
    ncf.flag = 1;  // Problematic with signed
    
    return 0;
}
