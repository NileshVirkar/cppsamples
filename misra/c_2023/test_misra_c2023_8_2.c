// Test file for MISRA C:2023 Rule 8.2
// Function types shall be in prototype form with named parameters

#include <stdint.h>

// Compliant examples
int compliant_function(int x, int y) {  // OK: Named parameters
    return x + y;
}

void compliant_process(uint32_t value, const char *name) {  // OK: Named parameters
    (void)value;
    (void)name;
}

int compliant_single_param(int count) {  // OK: Named parameter
    return count * 2;
}

void compliant_no_params(void) {    // OK: Explicit void
    // No parameters
}

// Non-compliant examples

// Unnamed parameters in prototype
int non_compliant_unnamed(int, int);  // EMB-ISSUE: [MISRA-C2023-8-2] - Unnamed parameters

// Definition with unnamed parameters
int non_compliant_unnamed(int x, int y) {  // Declaration above is non-compliant
    return x + y;
}

// Old-style function declaration (no prototype)
// void old_style();                 // EMB-ISSUE: [MISRA-C2023-8-2] - No prototype

// Mixed named and unnamed
void non_compliant_mixed(int x, int, char *);  // EMB-ISSUE: [MISRA-C2023-8-2] - Some unnamed

// Forward declaration without names
void non_compliant_forward(int, char *);  // EMB-ISSUE: [MISRA-C2023-8-2] - No names

void non_compliant_forward(int value, char *str) {  // Definition is OK, but declaration isn't
    (void)value;
    (void)str;
}

// Function pointer without parameter names
typedef int (*func_ptr_unnamed)(int, int);  // EMB-ISSUE: [MISRA-C2023-8-2] - Unnamed params

// Compliant function pointer
typedef int (*func_ptr_named)(int x, int y);  // OK: Named parameters

// Array of function pointers
int (*array_unnamed[])(int, int) = { NULL };  // EMB-ISSUE: [MISRA-C2023-8-2]

int (*array_named[])(int a, int b) = { NULL };  // OK: Named

// Callback declaration
void register_callback(void (*callback)(int));  // EMB-ISSUE: [MISRA-C2023-8-2] - Unnamed param

void register_callback_ok(void (*callback)(int event));  // OK: Named

int main(void) {
    compliant_function(1, 2);
    return 0;
}
