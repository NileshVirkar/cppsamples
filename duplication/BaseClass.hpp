// BaseClass.hpp
#ifndef BASE_CLASS_HPP
#define BASE_CLASS_HPP

namespace teh {
namespace types {

class BaseClass {
public:
    virtual ~BaseClass() = default;

    virtual double getStartAngle() const {
        return 0.0;
    }

    virtual double getEndAngle() const {
        return 0.0;
    }

    virtual bool isBridge() const {
        return false;
    }

    virtual bool isTunnel() const {
        return false;
    }

    // Additional virtual functions...
};

} // namespace types
} // namespace teh

#endif // BASE_CLASS_HPP
