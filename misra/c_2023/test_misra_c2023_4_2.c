// Test file for MISRA C:2023 Rule 4.2
// Trigraphs shall not be used

// Non-compliant examples
void non_compliant_examples() {
    // EMB-ISSUE: Trigraph for #
    char str1[] = "??=define";
    
    // EMB-ISSUE: Trigraph for backslash
    char str2[] = "path??/to??/file";
    
    // EMB-ISSUE: Trigraphs in array declaration
    int arr??<10??>;
    
    // EMB-ISSUE: Trigraph for |
    char str3[] = "What??!";
    
    // EMB-ISSUE: Trigraph for ^
    int value ??'= 5;
    
    // EMB-ISSUE: Trigraph for {
    int arr2??<??> = ??< 1, 2, 3 ??>;
}

// Compliant examples
void compliant_examples() {
    // Direct character usage
    char str1[] = "#define";
    char str2[] = "path\\to\\file";
    int arr[10];
    char str3[] = "What!";
    int value ^= 5;
    int arr2[] = { 1, 2, 3 };
    
    // Properly escaped question marks if needed
    char str4[] = "What?" "?";
    
    // Normal code without trigraphs
    int x = 42;
    char *ptr = &str1[0];
}
