#pragma once
#include "property.hpp"
#include "memory"


class Sensor {
public:
    Sensor(std::map<PropertyType, int>& propertyMap, PropertyType readValueType);
    float readValue();

private:
    std::map<PropertyType, int>& _propertyMap;

    PropertyType _readValueType;
};

