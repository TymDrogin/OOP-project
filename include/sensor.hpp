#pragma once
#include "property.hpp"
#include "memory"


class Sensor {
public:
    Sensor(std::shared_ptr<std::map<PropertyType, int>> propertyMap);
    virtual float readValue();
protected:
    std::shared_ptr<std::map<PropertyType, int>> _propertyMap;
};

