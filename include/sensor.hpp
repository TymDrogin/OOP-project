#pragma once
#include "property.hpp"
#include "memory"


class Sensor {
public:
    Sensor(const int ID, std::map<PropertyType, int>& propertyMap, PropertyType readValueType);
    int readValue();

private:
    std::map<PropertyType, int>& _propertyMap;

    PropertyType _readValueType;

    const int _ID;
};

