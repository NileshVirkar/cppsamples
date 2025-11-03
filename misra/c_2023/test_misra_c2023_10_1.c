// Test file for MISRA C:2023 Rule 10.1
// Operands shall not be of an inappropriate essential type

#include <stdint.h>
#include <stdbool.h>

// Compliant examples
void compliant_operations(void) {
    int x = 10;
    int y = 20;
    int result = x + y;         // OK: Both int
    
    unsigned int ux = 10U;
    unsigned int uy = 20U;
    unsigned int uresult = ux + uy;  // OK: Both unsigned int
    
    float f1 = 3.14f;
    float f2 = 2.71f;
    float fresult = f1 + f2;    // OK: Both float
    
    _Bool b1 = true;
    _Bool b2 = false;
    _Bool bresult = b1 && b2;   // OK: Boolean operation on bool
    
    (void)result; (void)uresult;
    (void)fresult; (void)bresult;
}

// Non-compliant examples
void non_compliant_mixed_types(void) {
    int x = 10;
    float f = 3.14f;
    float result = x + f;       // EMB-ISSUE: [MISRA-C2023-10-1] - Mixed int and float
    
    unsigned int ui = 10U;
    int si = 20;
    int mixed = ui + si;        // EMB-ISSUE: [MISRA-C2023-10-1] - Mixed signed/unsigned
    
    (void)result; (void)mixed;
}

void non_compliant_bool_arithmetic(void) {
    _Bool b = true;
    int x = b + 10;             // EMB-ISSUE: [MISRA-C2023-10-1] - Boolean in arithmetic
    
    _Bool b1 = true;
    _Bool b2 = false;
    int sum = b1 + b2;          // EMB-ISSUE: [MISRA-C2023-10-1] - Boolean addition
    
    (void)x; (void)sum;
}

void non_compliant_pointer_arithmetic(void) {
    int arr[10];
    int *ptr = arr;
    
    int bad = ptr + 3.5;        // EMB-ISSUE: [MISRA-C2023-10-1] - Float in pointer arithmetic
    (void)bad;
}

void non_compliant_char_arithmetic(void) {
    char c1 = 'A';
    char c2 = 'B';
    int result = c1 * c2;       // EMB-ISSUE: [MISRA-C2023-10-1] - Inappropriate char multiplication
    (void)result;
}

void non_compliant_enum_arithmetic(void) {
    enum Color { RED, GREEN, BLUE };
    enum Color c = RED;
    int x = c + 10;             // EMB-ISSUE: [MISRA-C2023-10-1] - Enum in arithmetic
    (void)x;
}

void non_compliant_bitwise_float(void) {
    float f = 3.14f;
    int bad = (int)f & 0xFF;    // Cast OK, but conceptually problematic
    
    // This would be clearly wrong (not compilable)
    // int worse = f & 0xFF;    // Error: invalid operands to binary &
    
    (void)bad;
}

int main(void) {
    compliant_operations();
    return 0;
}
