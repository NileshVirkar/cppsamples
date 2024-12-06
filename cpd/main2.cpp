#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function 1: Adds two numbers and returns the sum
int add(int a, int b) {
    return a + b;
}

// Function 2: Finds the maximum element in a vector
int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Vector is empty.");
    }
    return *std::max_element(numbers.begin(), numbers.end());
}

// Function 3: Calculates the factorial of a number
unsigned long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative numbers do not have a factorial.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function 4: Checks if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function 5: Prints a greeting message
void printGreeting(const std::string& name) {
    std::cout << "Hello, " << name << "! Welcome to the program." << std::endl;
}

int main() {
    // Example usage
    std::cout << "Addition: " << add(5, 7) << std::endl;
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9};
    std::cout << "Max Element: " << findMax(numbers) << std::endl;
    std::cout << "Factorial: " << factorial(5) << std::endl;
    std::cout << "Is Prime (7): " << (isPrime(7) ? "Yes" : "No") << std::endl;
    printGreeting("Alice");
    return 0;
}
