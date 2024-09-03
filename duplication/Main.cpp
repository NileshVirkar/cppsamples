// Main.cpp
#include <iostream>
#include "DerivedClass.hpp"

int main() {
    teh::types::DerivedClass derived;

    std::cout << "Start Angle: " << derived.getStartAngle() << std::endl;
    std::cout << "End Angle: " << derived.getEndAngle() << std::endl;
    std::cout << "Is Bridge: " << std::boolalpha << derived.isBridge() << std::endl;
    std::cout << "Is Tunnel: " << std::boolalpha << derived.isTunnel() << std::endl;

    return 0;
}
