// Test file for MISRA C:2023 Rule 3.1
// The character sequences /* and // shall not be used within a comment

// Compliant examples
/* This is a proper comment */
// This is also a proper comment

/* Multi-line comment
   that spans several lines
   without any nested markers */

// Single line comment without issues

/* Comment with asterisks ** but not followed by slash */

// Non-compliant examples

/* This comment has a nested /* marker inside */ // EMB-ISSUE: [MISRA-C2023-3-1]

// This comment mentions /* block comment syntax */ // EMB-ISSUE: [MISRA-C2023-3-1]

/* Another /* nested comment */ attempt */ // EMB-ISSUE: [MISRA-C2023-3-1]

/* Comment using // line comment marker inside */ // EMB-ISSUE: [MISRA-C2023-3-1]

// Comment with /* inside it */ // EMB-ISSUE: [MISRA-C2023-3-1]

int main(void) {
    int x = 10;
    /* Regular comment */
    int y = 20;
    return 0;
}
