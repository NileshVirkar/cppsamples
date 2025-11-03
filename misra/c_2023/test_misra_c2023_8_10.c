// Test file for MISRA C:2023 Rule 8.10
// An inline function shall be declared with the static storage class

// EMB-ISSUE: Inline without static
inline int square(int x) {
    return x * x;
}

// EMB-ISSUE: Another inline without static
inline void process_value(int val) {
    int result = val * 2;
}

// EMB-ISSUE: Inline function missing static
inline int add(int a, int b) {
    return a + b;
}

// Compliant: static inline
static inline int compliant_square(int x) {
    return x * x;
}

// Compliant: Another static inline
static inline void compliant_process(int val) {
    int result = val * 3;
}

// Compliant: static inline function
static inline int multiply(int a, int b) {
    return a * b;
}

// EMB-ISSUE: Inline in header style without static
inline int cube(int x) {
    return x * x * x;
}

// Compliant: Regular function (not inline)
int regular_function(int x) {
    return x + 1;
}

// Usage
void test_functions(void) {
    int a = square(5);
    int b = compliant_square(5);
    int c = add(3, 4);
    int d = multiply(3, 4);
    int e = cube(2);
    int f = regular_function(10);
}
