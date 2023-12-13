#pragma once

#include "sensor.hpp"
#include "command.hpp"
#include "ruleProcessor.hpp"
#include "zone.hpp"

class HouseManager {
public:
    void processCommandsFromFile(CommandFromFile& command);
    void processCommandFromString(Command& command);

    void advance();
private:
    std::vector<Zone> _zones;

    void hRem(); // uses destructor for all the parts of house
    void zNew(); // creates new zone in the position
};

