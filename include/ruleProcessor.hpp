#pragma once
#include "sensor.hpp"


#include <memory>

class Rule {
protected:
    std::unique_ptr<Sensor> _sensor;
    Rule(Sensor& sensor);

public:
    virtual bool evaluate() = 0;
};