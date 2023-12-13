#include "sensor.hpp"

Sensor::Sensor(std::map<PropertyType, int>& propertyMap, PropertyType readValueType)
        : _propertyMap(propertyMap), _readValueType(readValueType) {
}


float Sensor::readValue() {
    return _propertyMap[_readValueType];
}
