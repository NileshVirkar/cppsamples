// Test file for MISRA C:2023 Rule 5.3
// An identifier declared in an inner scope shall not hide an identifier in an outer scope

int global_var = 10;

// Compliant examples
void compliant_scope(void) {
    int local_var = 20;
    {
        int inner_var = 30;  // OK: Different name from outer scope
        local_var = inner_var;
    }
}

void compliant_function(int param) {
    int local = param + 10;
    {
        int result = local * 2;  // OK: Different names
        (void)result;
    }
}

// Non-compliant examples
void non_compliant_hiding_global(void) {
    int global_var = 20;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides global variable
    (void)global_var;
}

void non_compliant_hiding_local(void) {
    int x = 10;
    {
        int x = 20;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides outer scope x
        (void)x;
    }
}

void non_compliant_nested_blocks(void) {
    int counter = 0;
    {
        int value = 10;
        {
            int counter = 5;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides outer counter
            int value = 20;   // EMB-ISSUE: [MISRA-C2023-5-3] - Hides outer value
            (void)counter;
            (void)value;
        }
    }
}

void non_compliant_loop_hiding(void) {
    int i = 0;
    for (int i = 0; i < 10; i++) {  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides outer i
        // loop body
    }
}

void non_compliant_parameter_hiding(int x) {
    {
        int x = 10;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides parameter x
        (void)x;
    }
}

void outer_function(void) {
    int data = 100;
    {
        int data = 200;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides outer data
        {
            int data = 300;  // EMB-ISSUE: [MISRA-C2023-5-3] - Hides middle data
            (void)data;
        }
    }
}

int main(void) {
    compliant_scope();
    return 0;
}
