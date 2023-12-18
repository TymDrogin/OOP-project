#include "houseManager.hpp"

void HouseManager::processCommand(Command cmd) {
    // If invalid command has been sent exeption
    if(!cmd.getCommandType()) {
        throw std::logic_error("Invalid command has been passed to the manager");
    }

    CommandType cmdType = cmd.getCommandType().value();

    switch (cmdType) {

    }
}

void HouseManager::next() {
    for(auto &zone : _zones) {
        zone->nextStep();
    }
}

void HouseManager::advance(int steps) {
    for(int i = 0; i < steps; i++) {
        next();
    }
}

void HouseManager::hRem() {
    _zones.clear();
}

void HouseManager::zNew(int pos_x, int pos_y) {
    int index = pos_y * _zonesDimension_H + pos_x;
    int zoneID = _ZoneIDGenerator.getUnique();

    _zones[index] = std::make_unique<Zone>(zoneID);
}

