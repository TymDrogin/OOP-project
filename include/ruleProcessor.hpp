#pragma once
#include "sensor.hpp"
#include "device.hpp"

#include <vector>
#include <memory>


class Rule {
protected:
    Rule(const int ID, Sensor& sensor, Device& device);
    Device& _device;
    Sensor& _sensor;
    const int _ID;

public:
    virtual void evaluate() = 0;
};


class EqualTo : private Rule {
public:
    EqualTo(const int ID, Sensor &sensor, Device &device, int x);
    void evaluate() override;
private:
    int _x;
};

class LessThen : private Rule {
public:
    LessThen(const int ID, Sensor &sensor, Device &device, int x);
    void evaluate() override;
private:
    int _x;
};

class BiggerThen : private Rule {
public:
    BiggerThen(const int ID, Sensor &sensor, Device &device, int x);
    void evaluate() override;
private:
    int _x;
};

class InBetween : private Rule {
public:
    InBetween(const int ID, Sensor &sensor, Device &device, int x, int y);
    void evaluate() override;
private:
    int _x, _y;
};

class Outside : private Rule {
public:
    Outside(const int ID, Sensor &sensor, Device &device, int x, int y);
    void evaluate() override;
private:
    int _x, _y;
};


class RuleProcessor {
private:
    std::vector<std::unique_ptr<Rule>>& _rules;

public:
    explicit RuleProcessor(std::vector<std::unique_ptr<Rule>>& rules_ref);

    void process();
};

