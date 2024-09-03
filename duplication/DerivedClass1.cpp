// DerivedClass1.cpp
#include "BaseClass.hpp"
#include <iostream>

namespace teh {
namespace types {

class DerivedClass1 : public BaseClass {
public:
    double getStartAngle() const override {
        return 30.0;
    }

    double getEndAngle() const override {
        return 60.0;
    }

    bool isBridge() const override {
        return true;
    }

    bool isTunnel() const override {
        return false;
    }

    void printInfo() const {
        std::cout << "DerivedClass1 Info: Start Angle = " << getStartAngle()
                  << ", End Angle = " << getEndAngle()
                  << ", Is Bridge = " << std::boolalpha << isBridge()
                  << ", Is Tunnel = " << std::boolalpha << isTunnel()
                  << std::endl;
    }
};

} // namespace types
} // namespace teh
