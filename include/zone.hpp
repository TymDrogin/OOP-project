#pragma once
#include "sensor.hpp"
#include "ruleProcessor.hpp"
#include "property.hpp"
#include "utils.hpp"

#include <vector>
#include <map>

// TODO: Default initializer for the property
// Conditional delete of zones
// Add global ID counter as SINGLETONE

class Zone {
private:
    std::vector<Sensor> _sensors;
    std::map<PropertyType, int> _properties;
    std::vector<Device> _devises;
    std::vector<std::unique_ptr<Rule>> _rules;
    const int _ID;

    IDGeneator _sensorIDGenerator;
    IDGeneator _deviceIDGenerator;
    IDGeneator _ruleIDGenerator;

    RuleProcessor _ruleProcessor;

    void initializeProperties(); // Used to set default values

public:
    Zone(const int ID);
};