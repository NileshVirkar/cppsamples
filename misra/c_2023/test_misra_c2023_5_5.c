// Test file for MISRA C:2023 Rule 5.5
// Identifiers shall be distinct from macro names

// Compliant examples
#define MAX_VALUE 100

void compliant_function(void) {
    int max_count = 50;  // OK: different from MAX_VALUE
    int total = 0;       // OK: no macro with this name
}

#define BUFFER_SIZE 200

int calculate_buffer(void) {
    int buffer_length = BUFFER_SIZE;  // OK: different name
    return buffer_length;
}

// Non-compliant examples

#define MAX 100

void non_compliant1(void) {
    int MAX = 50;  // EMB-ISSUE: [MISRA-C2023-5-5] - Variable name same as macro
    int total = MAX;
}

#define SIZE 200

int SIZE;  // EMB-ISSUE: [MISRA-C2023-5-5] - Global variable conflicts with macro

void non_compliant2(void) {
    int SIZE = 300;  // EMB-ISSUE: [MISRA-C2023-5-5] - Local variable conflicts with macro
}

#define COUNT 10

struct Data {
    int COUNT;  // EMB-ISSUE: [MISRA-C2023-5-5] - Struct member conflicts with macro
};

#define TIMEOUT 1000

void TIMEOUT(void) {  // EMB-ISSUE: [MISRA-C2023-5-5] - Function name conflicts with macro
    // implementation
}

int main(void) {
    int value = MAX_VALUE;
    return 0;
}
