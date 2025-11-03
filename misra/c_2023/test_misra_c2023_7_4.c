// Test file for MISRA C:2023 Rule 7.4
// A string literal shall not be assigned to an object unless the object's type is pointer to const-qualified char

#include <string.h>

// Compliant examples
void compliant_string_assignments(void) {
    const char *str1 = "Hello";         // OK: pointer to const char
    const char *str2 = "World";         // OK: pointer to const char
    
    const char * const str3 = "Fixed";  // OK: const pointer to const char
    
    // Array initialization (copies the string)
    char array[] = "Array";             // OK: Array initialization
    
    (void)str1; (void)str2; (void)str3;
    (void)array;
}

// Non-compliant examples
void non_compliant_non_const(void) {
    char *str1 = "Hello";               // EMB-ISSUE: [MISRA-C2023-7-4] - Not const-qualified
    char *str2 = "World";               // EMB-ISSUE: [MISRA-C2023-7-4] - Not const-qualified
    
    // Attempting to modify would be undefined behavior
    // str1[0] = 'h';  // Undefined behavior
    
    (void)str1; (void)str2;
}

void non_compliant_function_param(char *param) {  // Parameter should be const char*
    param = "String";                   // EMB-ISSUE: [MISRA-C2023-7-4] - Assigning to non-const
    (void)param;
}

void non_compliant_assignments(void) {
    char *ptr;
    ptr = "Literal";                    // EMB-ISSUE: [MISRA-C2023-7-4] - Non-const pointer
    
    char *another = (char*)"Cast";      // EMB-ISSUE: [MISRA-C2023-7-4] - Cast doesn't make it right
    
    (void)ptr; (void)another;
}

void non_compliant_arrays_vs_pointers(void) {
    char array[] = "OK";                // OK: Array initialization (copy)
    char *ptr = "NotOK";                // EMB-ISSUE: [MISRA-C2023-7-4] - Pointer not const
    
    // array can be modified, ptr should not point to modifiable string literal
    array[0] = 'o';                     // OK: Modifying array copy
    // ptr[0] = 'n';                    // Would be undefined behavior
    
    (void)ptr;
}

char *non_compliant_return(void) {
    return "String";                    // EMB-ISSUE: [MISRA-C2023-7-4] - Return type not const
}

int main(void) {
    compliant_string_assignments();
    return 0;
}
