#pragma once
#include "sensor.hpp"
#include "device.hpp"

#include <vector>
#include <memory>


class Rule {
protected:
    Rule(Sensor& sensor, Device& device);
    std::unique_ptr<Device> _device;
    std::unique_ptr<Sensor> _sensor;

public:
    virtual void evaluate() = 0;
};


class EqualTo : private Rule {
public:
    EqualTo();
    void evaluate() override;
};

class LessThen : private Rule {
public:
    LessThen();
    void evaluate() override;
};

class BiggerThen : private Rule {
public:
    BiggerThen();
    void evaluate() override;
};

class InBetween : private Rule {
public:
    InBetween();
    void evaluate() override;
};

class Outside : private Rule {
public:
    Outside();
    void evaluate() override;
};


class RuleProcessor {
private:
    std::vector<Rule>* _rules;

public:
    explicit RuleProcessor(std::vector<Rule>* rules_ptr);

    void process();
};

