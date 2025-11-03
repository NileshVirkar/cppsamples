// Test file for MISRA C:2023 Rule 8.5
// An external object or function shall be declared once in one and only one file

// Compliant example - declaration in header (simulated here)
extern int global_counter;  // Single declaration

void compliant_function(void);  // Single declaration

// In practice, these should be in a header file included by multiple .c files

// Non-compliant examples - multiple declarations in same file
// (In real scenario, these would be in different files)

extern int duplicate_var;  // First declaration
extern int duplicate_var;  // EMB-ISSUE: [MISRA-C2023-8-5] - Duplicate declaration

void duplicate_func(void);  // First declaration
void duplicate_func(void);  // EMB-ISSUE: [MISRA-C2023-8-5] - Duplicate declaration

extern int multi_declared;  // First declaration
extern int multi_declared;  // EMB-ISSUE: [MISRA-C2023-8-5] - Second declaration
extern int multi_declared;  // EMB-ISSUE: [MISRA-C2023-8-5] - Third declaration

void process_data(void);   // First declaration
void process_data(void);   // EMB-ISSUE: [MISRA-C2023-8-5] - Duplicate

// Definitions (allowed, but declarations should be once)
int global_counter = 0;

void compliant_function(void) {
    global_counter++;
}

int main(void) {
    compliant_function();
    return 0;
}
