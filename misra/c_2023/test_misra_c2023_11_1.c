// Test file for MISRA C:2023 Rule 11.1
// Conversions shall not be performed between a pointer to a function and any other type

#include <stdint.h>

// Function declarations
void my_function(int x) {
    (void)x;
}

int another_function(void) {
    return 42;
}

// Compliant examples
void compliant_function_pointers(void) {
    typedef void (*func_ptr_t)(int);
    
    func_ptr_t fp = my_function;  // OK: Function pointer to compatible function
    
    void (*fp2)(int) = my_function;  // OK: Direct function pointer assignment
    
    fp(10);  // OK: Calling through function pointer
    
    // Function pointer to compatible function pointer
    typedef int (*func_ptr2_t)(void);
    func_ptr2_t fp3 = another_function;  // OK
}

// Non-compliant examples
void non_compliant_conversions(void) {
    // Function pointer to void pointer
    void *vp = (void*)my_function;  // EMB-ISSUE: [MISRA-C2023-11-1] - Function pointer to void*
    
    // Function pointer to data pointer
    typedef void (*func_ptr_t)(int);
    func_ptr_t fp = my_function;
    char *cp = (char*)fp;  // EMB-ISSUE: [MISRA-C2023-11-1] - Function pointer to data pointer
    
    // Integer to function pointer
    int (*fp2)(void) = (int(*)(void))0x12345678;  // EMB-ISSUE: [MISRA-C2023-11-1] - Integer to function pointer
    
    // Function pointer to integer
    uintptr_t addr = (uintptr_t)my_function;  // EMB-ISSUE: [MISRA-C2023-11-1] - Function pointer to integer
    
    // Void pointer to function pointer
    void *void_ptr = NULL;
    func_ptr_t fp3 = (func_ptr_t)void_ptr;  // EMB-ISSUE: [MISRA-C2023-11-1] - void* to function pointer
    
    // Function pointer through generic pointer
    void *generic = (void*)another_function;  // EMB-ISSUE: [MISRA-C2023-11-1]
    int (*restored)(void) = (int(*)(void))generic;  // EMB-ISSUE: [MISRA-C2023-11-1]
}

int main(void) {
    compliant_function_pointers();
    non_compliant_conversions();
    return 0;
}
