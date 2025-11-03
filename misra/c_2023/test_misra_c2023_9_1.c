// Test file for MISRA C:2023 Rule 9.1
// The value of an object with automatic storage duration shall not be read before it has been set

#include <stdint.h>

// Compliant examples
void compliant_initialization(void) {
    int x = 10;                 // OK: Initialized before use
    int y = x + 5;              // OK: x has been set
    
    int z;
    z = 20;                     // OK: Set before use
    int w = z;                  // OK: z has been set
    
    (void)y; (void)w;
}

void compliant_conditional(int flag) {
    int value;
    
    if (flag) {
        value = 10;
    } else {
        value = 20;
    }
    
    int result = value;         // OK: Set in all paths
    (void)result;
}

// Non-compliant examples
void non_compliant_uninitialized(void) {
    int x;
    int y = x + 5;              // EMB-ISSUE: [MISRA-C2023-9-1] - x not initialized
    
    int z;
    if (z > 0) {                // EMB-ISSUE: [MISRA-C2023-9-1] - z not initialized
        z = 10;
    }
    
    (void)y;
}

void non_compliant_partial_init(int flag) {
    int value;
    
    if (flag) {
        value = 10;
    }
    // else path doesn't set value
    
    int result = value;         // EMB-ISSUE: [MISRA-C2023-9-1] - Not set in all paths
    (void)result;
}

void non_compliant_array(void) {
    int arr[5];
    int x = arr[0];             // EMB-ISSUE: [MISRA-C2023-9-1] - Array not initialized
    (void)x;
}

void non_compliant_struct(void) {
    struct Data {
        int x;
        int y;
    };
    
    struct Data d;
    int value = d.x;            // EMB-ISSUE: [MISRA-C2023-9-1] - Struct not initialized
    (void)value;
}

void non_compliant_pointer(void) {
    int *ptr;
    int value = *ptr;           // EMB-ISSUE: [MISRA-C2023-9-1] - Pointer not initialized
    (void)value;
}

void non_compliant_loop(void) {
    int sum;
    for (int i = 0; i < 10; i++) {
        sum += i;               // EMB-ISSUE: [MISRA-C2023-9-1] - sum not initialized before +=
    }
    (void)sum;
}

int main(void) {
    compliant_initialization();
    return 0;
}
