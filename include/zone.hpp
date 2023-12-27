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
    std::vector<std::unique_ptr<Device>> _devises;
    std::vector<std::unique_ptr<Rule>> _rules;

    RuleProcessor _ruleProcessor;

    const int _ID;

    IDGenerator _sensorIDGenerator;
    IDGenerator _deviceIDGenerator;
    IDGenerator _ruleIDGenerator;

    void initializeProperties(); // Used to set default values

public:
    Zone(int ID);

    int getID() const;
    int getNumSensors() const;
    int getNumDevices() const;
    int getNumRules() const;

    void nextSimulationStep();
};