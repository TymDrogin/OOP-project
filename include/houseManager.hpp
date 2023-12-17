#pragma once

#include "sensor.hpp"
#include "command.hpp"
#include "ruleProcessor.hpp"
#include "zone.hpp"

class HouseManager {
public:
    void processCommand(Command cmd);
    void processCommandsFromFile(CommandFromFile cmd);


private:
    std::vector<Zone> _zones;
    void next();
    void advance(int steps);


    void hRem(); // uses destructor for all the parts of house
    void zNew(); // creates new zone in the position
};

