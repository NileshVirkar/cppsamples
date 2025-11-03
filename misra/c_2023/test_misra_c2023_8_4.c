// Test file for MISRA C:2023 Rule 8.4
// A compatible declaration shall be visible when an object or function with external linkage is defined

// Header simulation - these would normally be in a header file
extern int global_declared;
extern void function_declared(void);

// Compliant examples
int global_declared = 10;           // OK: Declaration visible above

void function_declared(void) {      // OK: Declaration visible above
    // Implementation
}

// Static (internal linkage) doesn't require prior declaration
static int internal_var = 20;       // OK: Internal linkage
static void internal_func(void) {   // OK: Internal linkage
    // Implementation
}

// Non-compliant examples

// External linkage without prior declaration
int global_undeclared = 30;         // EMB-ISSUE: [MISRA-C2023-8-4] - No prior declaration

void function_undeclared(void) {    // EMB-ISSUE: [MISRA-C2023-8-4] - No prior declaration
    // Implementation
}

// Another external without declaration
int another_global = 40;            // EMB-ISSUE: [MISRA-C2023-8-4]

void another_function(int x) {      // EMB-ISSUE: [MISRA-C2023-8-4]
    (void)x;
}

// Global array without declaration
int array_undeclared[10];           // EMB-ISSUE: [MISRA-C2023-8-4]

// External function with parameters
void process_undeclared(int a, int b) {  // EMB-ISSUE: [MISRA-C2023-8-4]
    (void)a;
    (void)b;
}

// Tentative definition without declaration
int tentative;                      // EMB-ISSUE: [MISRA-C2023-8-4]

// Multiple external objects
int ext1 = 1;                       // EMB-ISSUE: [MISRA-C2023-8-4]
int ext2 = 2;                       // EMB-ISSUE: [MISRA-C2023-8-4]
int ext3 = 3;                       // EMB-ISSUE: [MISRA-C2023-8-4]

int main(void) {
    function_declared();
    internal_func();
    return 0;
}
