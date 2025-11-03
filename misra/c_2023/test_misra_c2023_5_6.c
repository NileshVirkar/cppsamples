// Test file for MISRA C:2023 Rule 5.6
// A typedef name shall be a unique identifier

// Compliant examples
typedef int MyInt;
typedef float MyFloat;

void compliant_typedef(void) {
    MyInt x = 5;
    MyFloat y = 3.14f;
    int my_variable = 10;
    
    (void)x;
    (void)y;
    (void)my_variable;
}

// Non-compliant examples
int mytype = 5; // Variable
typedef int mytype; // EMB-ISSUE: [MISRA-C2023-5-6] - Typedef name conflicts with variable

void function_name(void) {
    // Function body
}

typedef int function_name; // EMB-ISSUE: [MISRA-C2023-5-6] - Typedef name conflicts with function name

int main(void) {
    compliant_typedef();
    return 0;
}
