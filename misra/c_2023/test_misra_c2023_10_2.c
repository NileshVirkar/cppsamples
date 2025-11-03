// Test file for MISRA C:2023 Rule 10.2
// Expressions of essentially character type shall not be used
// inappropriately in addition and subtraction operations

// EMB-ISSUE: Adding two characters inappropriately
void non_compliant_add() {
    char c1 = 'A';
    char c2 = 'B';
    char sum = c1 + c2;
}

// EMB-ISSUE: Subtracting characters inappropriately
void non_compliant_subtract() {
    char c1 = 'A';
    char c2 = 'B';
    char diff = c1 - c2;
}

// EMB-ISSUE: Mixed character arithmetic
void non_compliant_mixed() {
    unsigned char uc = 200;
    char c1 = 'A';
    char result = uc + c1;
}

// EMB-ISSUE: Characters in expression
void non_compliant_expression() {
    int value = 'Z' + 'A';
}

// Compliant: Calculating offset (appropriate use)
void compliant_offset() {
    char c1 = 'A';
    int offset = 'Z' - 'A';
}

// Compliant: Converting character to digit
void compliant_digit_conversion() {
    char digit = '5';
    int value = digit - '0';
}

// Compliant: Using character for array indexing
void compliant_indexing() {
    char c1 = 'C';
    char index = c1 - 'A';
    int array[26] = {0};
    int element = array[index];
}

// Compliant: Addition with integer
void compliant_integer_add() {
    char c1 = 'A';
    int ascii_value = c1 + 1;
}

// EMB-ISSUE: Character subtraction to character result
void non_compliant_char_result() {
    char result = 'M' - 'A';
}

// Compliant: Character comparison (not arithmetic)
void compliant_comparison() {
    char c1 = 'A';
    char c2 = 'B';
    int is_less = c1 < c2;
}

// Compliant: Using character values appropriately
void compliant_usage() {
    char letter = 'A';
    int code = letter;
    char next = code + 1;
}
