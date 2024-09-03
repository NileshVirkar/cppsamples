// DerivedClass2.cpp
#include "BaseClass.hpp"
#include <iostream>

namespace teh {
namespace types {

class DerivedClass2 : public BaseClass {
public:
    double getStartAngle() const override {
        return 45.0;
    }

    double getEndAngle() const override {
        return 90.0;
    }

    bool isBridge() const override {
        return false;
    }

    bool isTunnel() const override {
        return true;
    }

    void printInfo() const {
        std::cout << "DerivedClass2 Info: Start Angle = " << getStartAngle()
                  << ", End Angle = " << getEndAngle()
                  << ", Is Bridge = " << std::boolalpha << isBridge()
                  << ", Is Tunnel = " << std::boolalpha << isTunnel()
                  << std::endl;
    }
};

} // namespace types
} // namespace teh
