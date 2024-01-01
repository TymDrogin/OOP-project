#include "ruleProcessor.hpp"

Rule::Rule(int ID, Sensor &sensor, Device &device) : _ID(ID), _sensor(sensor), _device(device) {}


RuleProcessor::RuleProcessor(std::vector<std::unique_ptr<Rule>>& rules_ref) : _rules(rules_ref){}

void RuleProcessor::process() {
    for(auto &rule : _rules) {
        rule->evaluate();
    }
}

EqualTo::EqualTo(const int ID, Sensor &sensor, Device &device, int x) : Rule(ID, sensor, device), _x(x) {}
void EqualTo::evaluate() {
    if(_sensor.readValue() == _x) {
        _device.turnOff();
    }
}

LessThen::LessThen(const int ID, Sensor &sensor, Device &device, int x) : Rule(ID, sensor, device), _x(x){}
void LessThen::evaluate() {
    if(_sensor.readValue() < _x) {
        _device.turnOff();
    }
}

BiggerThen::BiggerThen(const int ID, Sensor &sensor, Device &device, int x) : Rule(ID, sensor, device), _x(x){}
void BiggerThen::evaluate() {
    if(_sensor.readValue() > _x) {
        _device.turnOff();
    }
}

InBetween::InBetween(const int ID, Sensor &sensor, Device &device, int x, int y) : Rule(ID, sensor, device), _x(x), _y(y){}
void InBetween::evaluate() {
    if(_sensor.readValue() > _x && _sensor.readValue() < _y) {
        _device.turnOff();
    }
}

Outside::Outside(const int ID, Sensor &sensor, Device &device, int x, int y)  : Rule(ID, sensor, device), _x(x), _y(y) {}
void Outside::evaluate() {
    if(_sensor.readValue() < _x && _sensor.readValue() > _y) {
        _device.turnOff();
    }
}
