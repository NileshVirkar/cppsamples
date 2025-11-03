// Test file for MISRA C:2023 Rule 5.2
// Identifiers declared in the same scope and name space shall be distinct

// Compliant examples
void compliant_identifiers(void) {
    int identifier_v1 = 1;
    int identifier_v2 = 2;
    int short_name = 3;
    int another_name = 4;
    
    (void)identifier_v1;
    (void)identifier_v2;
    (void)short_name;
    (void)another_name;
}

// Non-compliant examples
void non_compliant_identifiers(void) {
    // Identifiers differ only after 31 characters
    int very_long_identifier_name_exceeds_31_chars_version1 = 1;
    int very_long_identifier_name_exceeds_31_chars_version2 = 2; // EMB-ISSUE: [MISRA-C2023-5-2] - Identifiers differ only after 31st character
    
    int another_very_long_identifier_that_is_too_long_v1 = 3;
    int another_very_long_identifier_that_is_too_long_v2 = 4; // EMB-ISSUE: [MISRA-C2023-5-2] - Identifiers differ only after 31st character
    
    (void)very_long_identifier_name_exceeds_31_chars_version1;
    (void)very_long_identifier_name_exceeds_31_chars_version2;
    (void)another_very_long_identifier_that_is_too_long_v1;
    (void)another_very_long_identifier_that_is_too_long_v2;
}

int main(void) {
    compliant_identifiers();
    non_compliant_identifiers();
    return 0;
}
