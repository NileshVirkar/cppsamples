// Test file for MISRA C:2023 Rule 17.7
// The value returned by a function having non-void return type shall be used

#include <stdio.h>
#include <string.h>

// Functions with return values
int calculate_sum(int a, int b) {
    return a + b;
}

int get_value(void) {
    return 42;
}

char *get_string(void) {
    return "Hello";
}

// Compliant examples
void compliant_use_return_values(void) {
    int result = calculate_sum(10, 20);     // OK: Return value used
    (void)result;
    
    int value = get_value();                // OK: Return value assigned
    (void)value;
    
    if (get_value() > 30) {                 // OK: Return value used in condition
        result = 0;
    }
    
    char *str = get_string();               // OK: Return value assigned
    (void)str;
    
    // Explicitly casting to void is acceptable
    (void)calculate_sum(5, 10);             // OK: Explicitly discarded
}

void compliant_library_functions(void) {
    char buffer[100];
    
    // Using return value
    if (snprintf(buffer, sizeof(buffer), "Test") < 0) {  // OK: Return value checked
        // Handle error
    }
    
    size_t len = strlen("Hello");           // OK: Return value used
    (void)len;
}

// Non-compliant examples
void non_compliant_ignore_return(void) {
    calculate_sum(10, 20);                  // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
    
    get_value();                            // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
    
    get_string();                           // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
}

void non_compliant_library_functions(void) {
    char buffer[100];
    
    snprintf(buffer, sizeof(buffer), "Test");  // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
    
    strlen("Hello");                        // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
    
    FILE *f = fopen("test.txt", "r");
    if (f != NULL) {
        fclose(f);                          // EMB-ISSUE: [MISRA-C2023-17-7] - Return value ignored
    }
}

void non_compliant_in_expression(void) {
    int x = 10;
    
    x + calculate_sum(5, 10);               // EMB-ISSUE: [MISRA-C2023-17-7] - Expression result unused
    
    get_value(), x = 20;                    // EMB-ISSUE: [MISRA-C2023-17-7] - Comma operator, first ignored
}

int *allocate_memory(void) {
    return (int *)malloc(sizeof(int) * 10);
}

void non_compliant_allocation(void) {
    allocate_memory();                      // EMB-ISSUE: [MISRA-C2023-17-7] - Memory leak, return ignored
}

void non_compliant_comparison(void) {
    strcmp("hello", "world");               // EMB-ISSUE: [MISRA-C2023-17-7] - Comparison result ignored
    
    memcmp("abc", "def", 3);                // EMB-ISSUE: [MISRA-C2023-17-7] - Comparison result ignored
}

int main(void) {
    compliant_use_return_values();
    return 0;
}
