// Test file for MISRA C:2023 Rule 8.1
// Types shall be explicitly specified

#include <stdint.h>

// Compliant examples
int compliant_function(void) {      // OK: Explicit return type
    return 0;
}

void compliant_void(void) {         // OK: Explicit void
    int x = 10;                     // OK: Explicit type
    (void)x;
}

uint32_t compliant_explicit(int32_t param) {  // OK: All types explicit
    uint32_t result = (uint32_t)param;
    return result;
}

// Non-compliant examples (mostly historical C)
// Note: Modern C requires explicit types, but MISRA emphasizes this

// Implicit int (old K&R C style) - not valid in modern C
// compliant_implicit() {             // Would be EMB-ISSUE: [MISRA-C2023-8-1] - Implicit int
//     return 0;
// }

// Missing parameter types (old style)
// void old_style(x, y)              // Would be EMB-ISSUE: [MISRA-C2023-8-1]
// int x, y;
// {
//     // function body
// }

// Implicit int in declaration
// extern value;                     // Would be EMB-ISSUE: [MISRA-C2023-8-1] - Implicit int

// const without type
// const MAX = 100;                  // Would be EMB-ISSUE: [MISRA-C2023-8-1] - Implicit int

// Modern C requires explicit types, so these issues are rare
// But MISRA requires explicit specification even when language allows inference

void function_with_explicit_types(void) {
    int x;                          // OK: Explicit int
    unsigned int y;                 // OK: Explicit unsigned int
    long z;                         // OK: Explicit long
    
    (void)x; (void)y; (void)z;
}

// Ensure all parameters have explicit types
void explicit_parameters(int a, char b, long c) {  // OK: All explicit
    (void)a; (void)b; (void)c;
}

int main(void) {
    compliant_function();
    return 0;
}
