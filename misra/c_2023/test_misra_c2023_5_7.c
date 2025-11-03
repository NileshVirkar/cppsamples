// Test file for MISRA C:2023 Rule 5.7
// A tag name shall be a unique identifier

// Compliant examples
struct GoodStruct {
    int x;
};

union GoodUnion {
    int i;
    float f;
};

enum GoodEnum {
    GOOD_VAL1,
    GOOD_VAL2
};

void compliant_tags(void) {
    struct GoodStruct s;
    union GoodUnion u;
    enum GoodEnum e;
    
    s.x = 10;
    u.i = 5;
    e = GOOD_VAL1;
    
    (void)s;
    (void)u;
    (void)e;
}

// Non-compliant examples
struct mytag {
    int x;
};

int mytag = 5; // EMB-ISSUE: [MISRA-C2023-5-7] - Tag name conflicts with variable

union anothertag {
    int i;
    float f;
};

void anothertag(void) {} // EMB-ISSUE: [MISRA-C2023-5-7] - Tag name conflicts with function

enum enumtag {
    VAL1,
    VAL2
};

typedef int enumtag; // EMB-ISSUE: [MISRA-C2023-5-7] - Tag name conflicts with typedef

int main(void) {
    compliant_tags();
    return 0;
}
