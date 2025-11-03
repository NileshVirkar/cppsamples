// Test file for MISRA C:2023 Rule 7.3
// The lowercase character "l" shall not be used in a literal suffix

// Compliant examples
void compliant_suffixes(void) {
    long l1 = 100L;             // OK: Uppercase L
    long long ll1 = 1000LL;     // OK: Uppercase LL
    unsigned long ul1 = 500UL;  // OK: Uppercase UL
    unsigned long long ull1 = 999ULL; // OK: Uppercase ULL
    
    long double ld = 3.14L;     // OK: Uppercase L for long double
    
    (void)l1; (void)ll1; (void)ul1;
    (void)ull1; (void)ld;
}

// Non-compliant examples
void non_compliant_lowercase_l(void) {
    long l1 = 100l;             // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase l (looks like 1)
    long long ll1 = 1000ll;     // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase ll
    unsigned long ul1 = 500ul;  // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase ul
    unsigned long long ull1 = 999ull; // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase ull
    
    long l2 = 200l;             // EMB-ISSUE: [MISRA-C2023-7-3] - Confusing with 2001
    
    (void)l1; (void)ll1; (void)ul1;
    (void)ull1; (void)l2;
}

void non_compliant_mixed_case(void) {
    long l1 = 100Ul;            // EMB-ISSUE: [MISRA-C2023-7-3] - Mixed case with lowercase l
    long long ll1 = 1000Ll;     // EMB-ISSUE: [MISRA-C2023-7-3] - Mixed case with lowercase l
    
    (void)l1; (void)ll1;
}

void non_compliant_floats(void) {
    long double ld1 = 3.14l;    // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase l
    long double ld2 = 2.718l;   // EMB-ISSUE: [MISRA-C2023-7-3] - Lowercase l
    
    (void)ld1; (void)ld2;
}

void non_compliant_in_expressions(void) {
    long x = 10l + 20l;         // EMB-ISSUE: [MISRA-C2023-7-3] - Both have lowercase l
    long long y = 100ll * 2ll;  // EMB-ISSUE: [MISRA-C2023-7-3] - Both have lowercase ll
    
    (void)x; (void)y;
}

int main(void) {
    compliant_suffixes();
    return 0;
}
