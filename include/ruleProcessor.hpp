#pragma once
#include "sensor.hpp"
#include "device.hpp"


#include <memory>


class RuleProcessor {




};





class Rule {
protected:

    Rule(Sensor& sensor);

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




