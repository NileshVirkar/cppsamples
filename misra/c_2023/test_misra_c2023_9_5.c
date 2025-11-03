// Test file for MISRA C:2023 Rule 9.5
// Where designated initializers are used, all initializers shall be designated

// EMB-ISSUE: Mixing designated and non-designated initializers
int arr1[] = {
    1,
    [2] = 3,
    4
};

struct Data {
    int a, b, c;
};

// EMB-ISSUE: Mixed initialization in struct
struct Data d1 = {
    1,
    .c = 3,
    .b = 2
};

// EMB-ISSUE: Array with mixed style
int values1[] = {
    10,
    20,
    [5] = 50,
    60
};

// EMB-ISSUE: Partial designated in struct
struct Data d2 = {
    .a = 1,
    2,
    .c = 3
};

// Compliant: All non-designated initializers
int arr2[] = {1, 2, 3, 4, 5};

// Compliant: All designated initializers
int arr3[] = {
    [0] = 1,
    [1] = 2,
    [2] = 3
};

// Compliant: Struct with all designated initializers
struct Data d3 = {
    .a = 1,
    .b = 2,
    .c = 3
};

// Compliant: Struct with all non-designated
struct Data d4 = {1, 2, 3};

// Compliant: Consistent designated initialization
int values2[] = {
    [0] = 10,
    [1] = 20,
    [5] = 50,
    [6] = 60
};

// EMB-ISSUE: Another mixed case
int arr4[] = {
    [0] = 100,
    200,
    [2] = 300
};

// Compliant: Empty initialization
int arr5[10] = {0};

// Compliant: All designated
struct Data d5 = {
    .a = 10,
    .b = 20,
    .c = 30
};
