// Test file for MISRA C:2023 Rule 4.1
// Octal and hexadecimal escape sequences shall be terminated

// Non-compliant examples
void non_compliant_examples() {
    // EMB-ISSUE: Ambiguous octal escape followed by digit
    char str1[] = "\0337";
    
    // EMB-ISSUE: Hexadecimal escape followed by hex digit
    char str2[] = "\x1aF";
    
    // EMB-ISSUE: Octal sequence ambiguity
    char c1 = '\0128';
    
    // EMB-ISSUE: Another hex ambiguity
    char str3[] = "\xABCDEF";
    
    // EMB-ISSUE: Octal followed by octal digit
    char str4[] = "\0777";
}

// Compliant examples
void compliant_examples() {
    // Properly terminated octal escape
    char str1[] = "\033" "7";
    
    // Separated hexadecimal escape
    char str2[] = "\x1a" "F";
    
    // Clear octal sequence
    char c1 = '\012';
    
    // Properly separated hex
    char str3[] = "\xAB" "CDEF";
    
    // Using explicit values
    char str4[] = "\077" "7";
    
    // Simple escape sequences
    char str5[] = "Hello\n";
    char str6[] = "\t\tTab";
}
