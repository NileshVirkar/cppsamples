// Test file for MISRA C:2023 Rule 5.8
// Identifiers that define objects or functions with external linkage shall be unique

// Compliant examples
extern int external_identifier_v1;
extern int external_identifier_v2;
extern void external_function_v1(void);
extern void external_function_v2(void);

void compliant_external(void) {
    external_identifier_v1 = 10;
    external_identifier_v2 = 20;
}

// Non-compliant examples
extern int very_long_external_identifier_exceeds_31_chars_version1;
extern int very_long_external_identifier_exceeds_31_chars_version2; // EMB-ISSUE: [MISRA-C2023-5-8] - External identifiers differ only after 31st character

extern void very_long_external_function_name_that_is_way_too_long_v1(void);
extern void very_long_external_function_name_that_is_way_too_long_v2(void); // EMB-ISSUE: [MISRA-C2023-5-8] - External identifiers differ only after 31st character

int main(void) {
    compliant_external();
    return 0;
}
