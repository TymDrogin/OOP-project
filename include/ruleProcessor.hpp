#pragma once
#include "sensor.hpp"
#include "device.hpp"

#include <vector>
#include <memory>


class Rule {
protected:

    Rule(Sensor& sensor);
    std::unique_ptr<Device> _device;
    std::unique_ptr<Sensor> _sensor;

public:
    virtual bool evaluate() = 0;
};


class EqualTo : private Rule {

};

class LessThen : private Rule {

};

class BiggerThen : private Rule {

};

class InBetween : private Rule {

};

class Outside : private Rule {

};


class RuleProcessor {
private:
    std::vector<Rule>* _rules;

public:
    RuleProcessor(std::vector<Rule>* rules);

    void process();
};

