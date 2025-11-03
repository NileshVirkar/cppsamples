// Test file for MISRA C:2023 Rule 8.9
// An object should be defined at block scope if its identifier
// only appears in a single function

// EMB-ISSUE: File-scope variable only used in one function
int temp_buffer_data[100];

// EMB-ISSUE: Another file-scope object used in single function
static int calculation_cache;

// EMB-ISSUE: File-scope constant only used once
const int MAX_SIZE = 1000;

// Compliant: Used in multiple functions
static int shared_counter = 0;

void process_data(void) {
    // Uses temp_buffer_data - should be defined here instead
    for (int i = 0; i < 100; i++) {
        temp_buffer_data[i] = i * 2;
    }
}

int calculate(int x) {
    // Uses calculation_cache - should be defined here
    calculation_cache = x * x;
    return calculation_cache + x;
}

void increment_shared(void) {
    shared_counter++;  // OK - used in multiple functions
}

void reset_shared(void) {
    shared_counter = 0;  // OK - used in multiple functions
}

// EMB-ISSUE: Array only used in one function
static char string_buffer[256];

void format_string(const char *input) {
    // Uses string_buffer
    for (int i = 0; input[i] != '\0'; i++) {
        string_buffer[i] = input[i];
    }
    string_buffer[255] = '\0';
}

// Compliant example with block scope
void proper_example(void) {
    int local_temp[50];  // Properly defined at block scope
    
    for (int i = 0; i < 50; i++) {
        local_temp[i] = i;
    }
}
