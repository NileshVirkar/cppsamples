// Test file for MISRA C:2023 Rule 5.1
// External identifiers shall be distinct

// Compliant examples
extern int global_variable_one;
extern int global_variable_two;
extern void process_data_input(void);
extern void process_data_output(void);

// Non-compliant examples - identifiers too similar

// These would be distinct in first 31 characters but very similar
extern int very_long_identifier_name_with_suffix_a;
extern int very_long_identifier_name_with_suffix_b;  // OK if within 31 chars

// These differ only after many characters
extern int configuration_setting_for_network_interface_one;
extern int configuration_setting_for_network_interface_two;  // EMB-ISSUE: [MISRA-C2023-5-1]

// Similar names differing in subtle ways
extern int max_buffer_size;
extern int max_buffer_sise;  // EMB-ISSUE: [MISRA-C2023-5-1] - Typo, too similar

extern void initialize_system_module(void);
extern void initialise_system_module(void);  // EMB-ISSUE: [MISRA-C2023-5-1] - US vs UK spelling

// Abbreviation confusion
extern int cfg_timeout_val;
extern int config_timeout_value;  // EMB-ISSUE: [MISRA-C2023-5-1] - Abbreviation vs full

// Case sensitivity issues (if identifiers differ only by case)
extern int DataBuffer;
extern int databuffer;  // EMB-ISSUE: [MISRA-C2023-5-1] - Only case difference

extern int ERROR_CODE;
extern int error_code;  // EMB-ISSUE: [MISRA-C2023-5-1] - Only case difference

// Underscore variations
extern int max_size;
extern int maxsize;  // EMB-ISSUE: [MISRA-C2023-5-1] - Underscore difference only

int main(void) {
    return 0;
}
