#pragma once

#include "sensor.hpp"
#include "command.hpp"
#include "ruleProcessor.hpp"
#include "zone.hpp"

class HouseManager {
public:
    void processCommandFile();
    void processCommand(Command& command);

    void advance();

};
