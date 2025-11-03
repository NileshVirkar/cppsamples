// Test file for MISRA C:2023 Rule 21.3
// The memory allocation and deallocation functions of <stdlib.h> shall not be used

#include <stdlib.h>
#include <string.h>

// Compliant examples (not using dynamic allocation)
void compliant_static_allocation(void) {
    // Stack allocation
    int buffer[100];                // OK: Static array
    char string[256];               // OK: Static array
    
    struct Data {
        int values[50];
    };
    struct Data data;               // OK: Static struct
    
    (void)buffer;
    (void)string;
    (void)data;
}

void compliant_fixed_size(void) {
    static int global_buffer[1000]; // OK: Static storage
    
    const int SIZE = 100;
    int local[100];                 // OK: Fixed size
    
    (void)global_buffer;
    (void)local;
}

// Non-compliant examples
void non_compliant_malloc(void) {
    int *ptr = malloc(100 * sizeof(int));    // EMB-ISSUE: [MISRA-C2023-21-3] - Using malloc
    
    if (ptr != NULL) {
        // Use ptr
        free(ptr);                           // EMB-ISSUE: [MISRA-C2023-21-3] - Using free
    }
}

void non_compliant_calloc(void) {
    char *buffer = calloc(256, sizeof(char)); // EMB-ISSUE: [MISRA-C2023-21-3] - Using calloc
    
    if (buffer != NULL) {
        strcpy(buffer, "Hello");
        free(buffer);                         // EMB-ISSUE: [MISRA-C2023-21-3] - Using free
    }
}

void non_compliant_realloc(void) {
    int *ptr = malloc(10 * sizeof(int));      // EMB-ISSUE: [MISRA-C2023-21-3] - Using malloc
    
    if (ptr != NULL) {
        int *new_ptr = realloc(ptr, 20 * sizeof(int)); // EMB-ISSUE: [MISRA-C2023-21-3] - Using realloc
        
        if (new_ptr != NULL) {
            ptr = new_ptr;
            free(ptr);                        // EMB-ISSUE: [MISRA-C2023-21-3] - Using free
        } else {
            free(ptr);                        // EMB-ISSUE: [MISRA-C2023-21-3] - Using free
        }
    }
}

struct Node {
    int data;
    struct Node *next;
};

void non_compliant_dynamic_struct(void) {
    struct Node *node = malloc(sizeof(struct Node)); // EMB-ISSUE: [MISRA-C2023-21-3]
    
    if (node != NULL) {
        node->data = 10;
        node->next = NULL;
        free(node);                           // EMB-ISSUE: [MISRA-C2023-21-3]
    }
}

void non_compliant_array_allocation(void) {
    int size = 100;
    int *array = malloc(size * sizeof(int));  // EMB-ISSUE: [MISRA-C2023-21-3]
    
    if (array != NULL) {
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        free(array);                          // EMB-ISSUE: [MISRA-C2023-21-3]
    }
}

void non_compliant_string_allocation(void) {
    char *str = malloc(100);                  // EMB-ISSUE: [MISRA-C2023-21-3]
    
    if (str != NULL) {
        strcpy(str, "Dynamic string");
        free(str);                            // EMB-ISSUE: [MISRA-C2023-21-3]
    }
}

int main(void) {
    compliant_static_allocation();
    return 0;
}
