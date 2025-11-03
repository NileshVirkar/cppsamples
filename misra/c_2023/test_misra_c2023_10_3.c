// Test file for MISRA C:2023 Rule 10.3
// The value of an expression shall not be assigned to an object with a narrower essential type

#include <stdint.h>

// Compliant examples
void compliant_assignments(void) {
    int32_t large = 100;
    int32_t same_size = large;  // OK: Same width
    
    int16_t small_val = 50;
    int32_t wider = small_val;  // OK: Widening conversion
    
    uint8_t byte = 200;
    uint16_t word = byte;  // OK: Widening
    
    float f = 3.14f;
    double d = f;  // OK: Widening
}

// Non-compliant examples - narrowing conversions
void non_compliant_assignments(void) {
    int32_t large_value = 100000;
    int16_t small_value = large_value;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing int32 to int16
    
    int64_t very_large = 1000000L;
    int32_t medium = very_large;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing int64 to int32
    
    unsigned int ui = 300;
    unsigned char uc = ui;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing int to char
    
    double d = 3.14159265358979;
    float f = d;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing double to float
    
    long long ll = 999999999LL;
    int i = ll;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing long long to int
    
    uint32_t u32 = 65535;
    uint16_t u16 = u32;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing uint32 to uint16
    
    int result = large_value + 1000;
    short s = result;  // EMB-ISSUE: [MISRA-C2023-10-3] - Narrowing int to short
}

int main(void) {
    compliant_assignments();
    non_compliant_assignments();
    return 0;
}
