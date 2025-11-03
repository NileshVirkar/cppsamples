// Test file for MISRA C:2023 Rule 9.4
// An element of an object shall not be initialized more than once

// EMB-ISSUE: Array with duplicate index initialization
int arr1[] = {
    [0] = 1,
    [1] = 2,
    [0] = 3
};

struct Data {
    int x;
    int y;
    int z;
};

// EMB-ISSUE: Struct with duplicate member initialization
struct Data d1 = {
    .x = 10,
    .y = 20,
    .x = 30
};

// EMB-ISSUE: Multiple initializations
struct Data d2 = {
    .x = 1,
    .y = 2,
    .z = 3,
    .y = 4
};

// EMB-ISSUE: Array with repeated index
int arr2[] = {
    [0] = 10,
    [1] = 20,
    [2] = 30,
    [1] = 40
};

// Compliant: Array with unique initializations
int arr3[] = {
    [0] = 1,
    [1] = 2,
    [2] = 3
};

// Compliant: Struct with single initialization per member
struct Data d3 = {
    .x = 30,
    .y = 20,
    .z = 10
};

// Compliant: Sequential initialization
struct Data d4 = {10, 20, 30};

// Compliant: Array without duplicates
int arr4[5] = {1, 2, 3, 4, 5};

// EMB-ISSUE: Designated initializer redefining element
int arr5[] = {
    [2] = 100,
    [3] = 200,
    [2] = 150
};

// Compliant: Proper designated init
int arr6[] = {
    [0] = 5,
    [2] = 10,
    [4] = 15
};
