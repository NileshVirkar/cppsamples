// Test file for MISRA C:2023 Rule 8.3
// All declarations of an object or function shall use the same names and type qualifiers

#include <stdint.h>

// Compliant examples
extern int global_value;        // Declaration
int global_value = 0;           // Definition - same name and type

void process_data(int count);   // Declaration
void process_data(int count) {  // Definition - same name and type
    (void)count;
}

extern const int max_size;      // Declaration with const
const int max_size = 100;       // Definition - same qualifiers

// Non-compliant examples

// Different parameter names
void function1(int value);      // Declaration
void function1(int count) {     // EMB-ISSUE: [MISRA-C2023-8-3] - Different parameter name
    (void)count;
}

// Inconsistent const qualifier
extern int variable1;           // Declaration without const
const int variable1 = 50;       // EMB-ISSUE: [MISRA-C2023-8-3] - Definition has const

// Different parameter names in multiple declarations
void function2(int x, int y);   // First declaration
void function2(int a, int b);   // EMB-ISSUE: [MISRA-C2023-8-3] - Different names

// Missing qualifier
extern const int config_value;  // Declaration with const
int config_value = 200;         // EMB-ISSUE: [MISRA-C2023-8-3] - Missing const in definition

// Inconsistent volatile
extern volatile int sensor_data; // Declaration with volatile
int sensor_data = 0;            // EMB-ISSUE: [MISRA-C2023-8-3] - Missing volatile

// Pointer qualifier inconsistency
extern int *ptr1;               // Declaration
int * const ptr1 = NULL;        // EMB-ISSUE: [MISRA-C2023-8-3] - Different qualifier

// Array size inconsistency
extern int array1[];            // Declaration
int array1[10];                 // OK: Size can be added in definition

extern int array2[10];          // Declaration
int array2[20];                 // EMB-ISSUE: [MISRA-C2023-8-3] - Different size

// Function parameter type inconsistency
void func3(int param);          // Declaration
void func3(long param) {        // EMB-ISSUE: [MISRA-C2023-8-3] - Different type
    (void)param;
}

// Return type inconsistency
int func4(void);                // Declaration
long func4(void) {              // EMB-ISSUE: [MISRA-C2023-8-3] - Different return type
    return 0;
}

int main(void) {
    process_data(10);
    return 0;
}
