// Test file for MISRA C:2023 Rule 3.2
// Line-splicing shall not be used in // comments

// Compliant examples
// This is a normal comment
int compliant1 = 10;

// Multi-line comments can use block style
/* This comment
   spans multiple lines
   using proper block comment syntax */
int compliant2 = 20;

// Another single-line comment
int compliant3 = 30;

// Non-compliant examples

// This comment uses line-splicing \
int non_compliant1 = 40; // EMB-ISSUE: [MISRA-C2023-3-2] - This line is commented out!

// Another line-splice \
int non_compliant2 = 50; // EMB-ISSUE: [MISRA-C2023-3-2]

// Backslash at end \
int x = 60; // EMB-ISSUE: [MISRA-C2023-3-2] - Hidden by line-splicing

// Line continuation in comment \
return 0; // EMB-ISSUE: [MISRA-C2023-3-2]

int main(void) {
    int a = 1;
    // Normal comment
    int b = 2;
    return 0;
}
