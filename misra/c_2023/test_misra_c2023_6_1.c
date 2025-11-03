// Test file for MISRA C:2023 Rule 6.1
// Bit-fields shall only be declared with an appropriate type

#include <stdint.h>

// Compliant examples
struct CompliantBitfield {
    unsigned int flag : 1;      // OK: unsigned int
    unsigned int status : 2;    // OK: unsigned int
    signed int value : 3;       // OK: explicitly signed int
    uint8_t byte : 4;          // OK: explicitly unsigned type
};

struct CompliantFlags {
    _Bool enabled : 1;          // OK: _Bool for single bit
    unsigned int mode : 3;      // OK: unsigned int
    signed int offset : 5;      // OK: explicitly signed
};

// Non-compliant examples
struct NonCompliantBitfield {
    int flag : 1;               // EMB-ISSUE: [MISRA-C2023-6-1] - Plain int (implementation-defined)
    int status : 2;             // EMB-ISSUE: [MISRA-C2023-6-1] - Plain int
    char value : 3;             // EMB-ISSUE: [MISRA-C2023-6-1] - char type (not appropriate)
};

struct NonCompliantMixed {
    unsigned int good : 1;      // OK
    int bad : 2;                // EMB-ISSUE: [MISRA-C2023-6-1] - Plain int
    short wrong : 3;            // EMB-ISSUE: [MISRA-C2023-6-1] - short not appropriate
};

struct NonCompliantTypes {
    char c : 4;                 // EMB-ISSUE: [MISRA-C2023-6-1] - char
    long l : 8;                 // EMB-ISSUE: [MISRA-C2023-6-1] - long not appropriate
    int i : 5;                  // EMB-ISSUE: [MISRA-C2023-6-1] - plain int
};

// Enum as bit-field (questionable)
enum Status { OFF, ON };
struct NonCompliantEnum {
    enum Status state : 1;      // EMB-ISSUE: [MISRA-C2023-6-1] - enum not appropriate
};

int main(void) {
    struct CompliantBitfield cb;
    struct NonCompliantBitfield ncb;
    
    cb.flag = 1;
    ncb.flag = 1;
    
    return 0;
}
