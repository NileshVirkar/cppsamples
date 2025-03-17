#include <iostream>

void checkNumber(int num) {
    if (num > 0) 
        std::cout << "Positive number"; // Violation: Missing curly braces

    if (num == 0) 
        std::cout << "Zero"; 
    else 
        std::cout << "Negative"; // Violation: Missing curly braces for else
}

int main() {
    checkNumber(5);
    return 0;
}
