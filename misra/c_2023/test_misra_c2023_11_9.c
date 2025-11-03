// Test file for MISRA C:2023 Rule 11.9
// The macro NULL shall be the only permitted form of integer null pointer constant

#include <stddef.h>  // For NULL

// Compliant examples
void compliant_null_usage(void) {
    int *p1 = NULL;             // OK: Using NULL macro
    char *p2 = NULL;            // OK: Using NULL macro
    void *p3 = NULL;            // OK: Using NULL macro
    
    if (p1 == NULL) {           // OK: Comparison with NULL
        // Handle null
    }
    
    if (p2 != NULL) {           // OK: Comparison with NULL
        // Handle non-null
    }
    
    (void)p3;
}

void compliant_function_param(int *ptr) {
    if (ptr == NULL) {          // OK: Using NULL
        return;
    }
    // Use ptr
}

int *compliant_return(void) {
    return NULL;                // OK: Returning NULL
}

// Non-compliant examples
void non_compliant_zero_literal(void) {
    int *p1 = 0;                // EMB-ISSUE: [MISRA-C2023-11-9] - Integer literal 0
    char *p2 = 0;               // EMB-ISSUE: [MISRA-C2023-11-9] - Integer literal 0
    
    if (p1 == 0) {              // EMB-ISSUE: [MISRA-C2023-11-9] - Comparing with 0
        p1 = NULL;
    }
    
    (void)p2;
}

void non_compliant_cast_zero(void) {
    int *p1 = (int *)0;         // EMB-ISSUE: [MISRA-C2023-11-9] - Cast of 0
    void *p2 = (void *)0;       // EMB-ISSUE: [MISRA-C2023-11-9] - Cast of 0
    
    (void)p1; (void)p2;
}

int *non_compliant_return(void) {
    return 0;                   // EMB-ISSUE: [MISRA-C2023-11-9] - Returning 0 for pointer
}

void non_compliant_comparison(int *ptr) {
    if (ptr == 0) {             // EMB-ISSUE: [MISRA-C2023-11-9] - Comparing with 0
        return;
    }
    
    if (0 == ptr) {             // EMB-ISSUE: [MISRA-C2023-11-9] - Comparing with 0
        return;
    }
}

void non_compliant_assignment(void) {
    int *p;
    p = 0;                      // EMB-ISSUE: [MISRA-C2023-11-9] - Assigning 0
    
    p = (int *)0;               // EMB-ISSUE: [MISRA-C2023-11-9] - Assigning cast 0
    
    (void)p;
}

void non_compliant_function_call(void) {
    void process(int *ptr);
    
    process(0);                 // EMB-ISSUE: [MISRA-C2023-11-9] - Passing 0 as pointer
    process((int *)0);          // EMB-ISSUE: [MISRA-C2023-11-9] - Passing cast 0
}

void process(int *ptr) {
    (void)ptr;
}

struct Node {
    int data;
    struct Node *next;
};

void non_compliant_struct_init(void) {
    struct Node n1 = {10, 0};   // EMB-ISSUE: [MISRA-C2023-11-9] - 0 for pointer in initializer
    struct Node n2 = {20, NULL}; // OK: Using NULL
    
    (void)n1; (void)n2;
}

int main(void) {
    compliant_null_usage();
    return 0;
}
