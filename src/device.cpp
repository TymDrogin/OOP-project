#include "device.hpp"

void Device::work() {
    if(_state) {
        _propertyMap[_affectedPropertyType] += _propertyAffectValue;
    }
}

void Device::turnOn() {
    _state = true;
}

void Device::turnOff() {
    _state = false;
}
