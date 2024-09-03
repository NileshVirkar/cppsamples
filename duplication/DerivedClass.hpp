// DerivedClass.hpp
#ifndef DERIVED_CLASS_HPP
#define DERIVED_CLASS_HPP

#include "BaseClass.hpp"

namespace teh {
namespace types {

class DerivedClass : public BaseClass {
public:
    double getStartAngle() const override {
        return 45.0;
    }

    double getEndAngle() const override {
        return 90.0;
    }

    bool isBridge() const override {
        return true;
    }

    bool isTunnel() const override {
        return true;
    }

    // Additional overrides...
};

} // namespace types
} // namespace teh

#endif // DERIVED_CLASS_HPP

