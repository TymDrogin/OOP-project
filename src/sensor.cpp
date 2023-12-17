#include "sensor.hpp"

Sensor::Sensor(const int ID, std::map<PropertyType, int>& propertyMap, PropertyType readValueType)
        :  _ID(ID), _propertyMap(propertyMap), _readValueType(readValueType) {
}


int Sensor::readValue() {
    return _propertyMap[_readValueType];
}
