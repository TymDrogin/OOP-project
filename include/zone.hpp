#pragma once
#include "sensor.hpp"
#include "ruleProcessor.hpp"
#include "property.hpp"

#include <vector>
#include <map>

// TODO: Default initializer for the property
// Conditional delete of zones
// Add global ID counter as SINGLETONE

class Zone {
private:
    std::vector<Sensor> _sensors;
    std::map<PropertyType, float> _properties;
    std::vector<Device> _devises;
    std::vector<Rule> _rules;

    RuleProcessor _ruleProcessor;

public:
    Zone();
};