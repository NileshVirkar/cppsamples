// Test file for MISRA C:2023 Rule 10.5
// The value of an expression should not be cast to an inappropriate essential type

#include <stdlib.h>
#include <stdint.h>

// EMB-ISSUE: Casting between signed and unsigned
void non_compliant_signedness() {
    int signed_val = -10;
    unsigned int unsigned_val = (unsigned int)signed_val;
}

// EMB-ISSUE: Pointer to integer cast
void non_compliant_ptr_to_int() {
    void *ptr = malloc(100);
    int address = (int)ptr;
    free(ptr);
}

// EMB-ISSUE: Integer to pointer
void non_compliant_int_to_ptr() {
    int val = 0x1000;
    int *ptr = (int *)val;
}

// EMB-ISSUE: Float to int
void non_compliant_float_to_int() {
    float f = 3.14159f;
    int i = (int)f;
}

// EMB-ISSUE: Incompatible pointer casts
void non_compliant_ptr_cast() {
    float *fptr = malloc(sizeof(float));
    int *iptr = (int *)fptr;
    free(fptr);
}

// EMB-ISSUE: Character to float
void non_compliant_char_to_float() {
    char c = 'A';
    float f = (float)c;
}

// Compliant: Safe casts between compatible types
void compliant_widening() {
    int i = 42;
    long l = (long)i;
}

// Compliant: Explicit intended conversion
void compliant_float_widening() {
    float f = 3.14159f;
    double d = (double)f;
}

// Compliant: Using proper types for addresses
void compliant_address() {
    void *ptr = malloc(100);
    uintptr_t address = (uintptr_t)ptr;
    free(ptr);
}

// Compliant: Pointer casting through void*
void compliant_void_ptr() {
    int *iptr = malloc(sizeof(int) * 10);
    void *vptr = (void *)iptr;
    int *iptr2 = (int *)vptr;
    free(iptr);
}

// Compliant: Using appropriate conversions
void compliant_unsigned_char() {
    unsigned char uc = 65;
    int i = (int)uc;
}

// EMB-ISSUE: Signed to unsigned without check
void non_compliant_signed_unsigned() {
    int x = -100;
    unsigned int y = (unsigned int)x;
}

// Compliant: Safe conversions
void compliant_conversions() {
    short s = 100;
    int i = (int)s;
    long l = (long)i;
}
