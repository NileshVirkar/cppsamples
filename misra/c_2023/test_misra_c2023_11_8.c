// Test file for MISRA C:2023 Rule 11.8
// A cast shall not remove any const or volatile qualification from the type pointed to by a pointer

#include <stdint.h>

// Compliant examples
void compliant_const_preservation(void) {
    const int value = 10;
    const int *cp = &value;     // OK: const preserved
    
    const int *cp2 = cp;        // OK: const to const
    
    int x = 20;
    const int *cp3 = &x;        // OK: Adding const is fine
    
    volatile int sensor = 100;
    volatile int *vp = &sensor; // OK: volatile preserved
    
    (void)cp2; (void)cp3; (void)vp;
}

void compliant_adding_qualifiers(void) {
    int x = 10;
    const int *cp = &x;         // OK: Adding const
    
    int y = 20;
    volatile int *vp = &y;      // OK: Adding volatile
    
    int z = 30;
    const volatile int *cvp = &z;  // OK: Adding both
    
    (void)cp; (void)vp; (void)cvp;
}

// Non-compliant examples
void non_compliant_remove_const(void) {
    const int value = 10;
    const int *cp = &value;
    
    int *p = (int *)cp;         // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const
    *p = 20;                    // Undefined behavior
}

void non_compliant_remove_volatile(void) {
    volatile int sensor = 100;
    volatile int *vp = &sensor;
    
    int *p = (int *)vp;         // EMB-ISSUE: [MISRA-C2023-11-8] - Removes volatile
    (void)p;
}

void non_compliant_remove_both(void) {
    const volatile int cv_value = 50;
    const volatile int *cvp = &cv_value;
    
    int *p = (int *)cvp;        // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const and volatile
    (void)p;
}

void non_compliant_pointer_to_pointer(void) {
    const int value = 10;
    const int *cp = &value;
    const int **cpp = &cp;
    
    int **pp = (int **)cpp;     // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const from pointed-to type
    (void)pp;
}

void non_compliant_function_param(const int *param) {
    int *p = (int *)param;      // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const
    *p = 100;                   // Undefined behavior
}

void non_compliant_string_literal(void) {
    const char *str = "Hello";
    char *p = (char *)str;      // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const
    // p[0] = 'h';              // Would be undefined behavior
    (void)p;
}

void non_compliant_array(void) {
    const int arr[] = {1, 2, 3};
    int *p = (int *)arr;        // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const
    p[0] = 10;                  // Undefined behavior
}

void non_compliant_struct_member(void) {
    struct Data {
        const int value;
    };
    
    const struct Data d = {100};
    struct Data *p = (struct Data *)&d;  // EMB-ISSUE: [MISRA-C2023-11-8] - Removes const
    (void)p;
}

int main(void) {
    compliant_const_preservation();
    return 0;
}
