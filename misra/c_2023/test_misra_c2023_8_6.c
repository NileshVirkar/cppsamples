// Test file for MISRA C:2023 Rule 8.6
// An identifier with external linkage shall have exactly one external definition

// Compliant examples - declarations and single definitions

extern int compliant_global;  // Declaration
int compliant_global = 10;    // Definition (exactly one)

extern void compliant_func(void);  // Declaration
void compliant_func(void) {        // Definition (exactly one)
    // implementation
}

// Non-compliant examples

// Multiple definitions (linker error in real multi-file project)
int duplicate_definition = 5;   // First definition
// int duplicate_definition = 10;  // Would be second definition in another file

// Declaration without definition
extern void missing_definition(void);  // EMB-ISSUE: [MISRA-C2023-8-6] - Declared but never defined

extern int missing_var;  // EMB-ISSUE: [MISRA-C2023-8-6] - Declared but never defined

// Forward declaration without definition
void forward_declared(void);  // EMB-ISSUE: [MISRA-C2023-8-6] - Declaration without definition

extern int external_no_def;  // EMB-ISSUE: [MISRA-C2023-8-6] - No definition provided

// In practice, this rule requires whole-program analysis
// to verify each external identifier has exactly one definition
// across all translation units

int main(void) {
    compliant_global = 20;
    compliant_func();
    return 0;
}
