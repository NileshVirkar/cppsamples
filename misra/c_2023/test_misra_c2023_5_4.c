// Test file for MISRA C:2023 Rule 5.4
// Macro identifiers shall be distinct

// Compliant examples
#define MAX_BUFFER_SIZE 100
#define MAX_STRING_LENGTH 200
#define MAX_ARRAY_COUNT 50

#define INPUT_TIMEOUT 1000
#define OUTPUT_TIMEOUT 2000

#define ENABLE_FEATURE_A 1
#define ENABLE_FEATURE_B 0

// Non-compliant examples - similar/confusing names

#define MAX_SIZE 100
#define MAX_SISE 200  // EMB-ISSUE: [MISRA-C2023-5-4] - Typo, very similar to MAX_SIZE

#define BUFFER_LEN 50
#define BUFFER_LENGTH 100  // EMB-ISSUE: [MISRA-C2023-5-4] - Abbreviation confusion

#define TIMEOUT_VALUE 1000
#define TIMEOUT_VAL 2000  // EMB-ISSUE: [MISRA-C2023-5-4] - Abbreviation too similar

#define CONFIG_ENABLE 1
#define CONFIG_ENABLED 0  // EMB-ISSUE: [MISRA-C2023-5-4] - Nearly identical

#define MAX_COUNT 10
#define MAXCOUNT 20  // EMB-ISSUE: [MISRA-C2023-5-4] - Only spacing difference

int main(void) {
    int buffer[MAX_BUFFER_SIZE];
    int timeout = INPUT_TIMEOUT;
    return 0;
}
