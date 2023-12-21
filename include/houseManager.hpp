#pragma once

#include "sensor.hpp"
#include "command.hpp"
#include "ruleProcessor.hpp"
#include "zone.hpp"
#include "utils.hpp"


class HouseManager {
public:
    void processCommand(Command cmd);
    void processCommandsFromFile(CommandFromFile cmd);


private:
    std::vector<std::unique_ptr<Zone>> _zones;
    IDGenerator _ZoneIDGenerator;

    int _zonesDimension_W, _zonesDimension_H;

    // -------Commands for simulated time-------
    void next();
    void advance(Command& cmd);

    // -------Commands for managing housing and zones------

    void hNova(Command& cmd);
    void hRem(); // uses destructor for all the parts of house
    void zNew(Command& cmd); // creates new zone in the position
};

