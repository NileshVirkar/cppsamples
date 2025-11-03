// Test file for MISRA C:2023 Rule 8.7
// Functions and objects should not be defined with external linkage
// if they are referenced in only one translation unit

// EMB-ISSUE: Function only used in this file - should be static
int helper_function(int x) {
    return x * 2;
}

// EMB-ISSUE: Variable only used in this file - should be static
int module_counter = 0;

// EMB-ISSUE: Another internal-only function
void internal_helper(void) {
    module_counter++;
}

// Compliant: static function
static int static_helper(int x) {
    return x * 3;
}

// Compliant: static variable
static int static_counter = 0;

// Compliant: Function meant to be used externally (has header declaration)
void public_api(void) {
    module_counter++;
    internal_helper();
    int result = helper_function(42);
    static_counter++;
}

// Compliant: Another public function
extern int get_value(void) {
    return module_counter;
}

// EMB-ISSUE: Array only used internally
const int lookup_table[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// Compliant: Static array
static const int static_table[5] = {1, 2, 3, 4, 5};
