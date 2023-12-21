#include "houseManager.hpp"

void HouseManager::processCommand(Command cmd) {
    // If invalid command has been sent exeption
    if(!cmd.getCommandType()) {
        throw std::logic_error("Invalid command has been passed to the manager");
    }

    CommandType cmdType = cmd.getCommandType().value();

    switch (cmdType) {
        case CommandType::Next:
            next();
            break;
        case CommandType::Advance:
            advance(cmd);
            break;
        case CommandType::Hnova:
            break;
    }
}

void HouseManager::next() {
    for(auto &zone : _zones) {
        zone->nextSimulationStep();
    }
}

void HouseManager::advance(Command& cmd) {
    int steps = std::stoi(cmd.getTokens()[1].getLexeme());
    for(int i = 0; i < steps; i++) {
        next();
    }
}


void HouseManager::hRem() {
    _zones.clear();
}

void HouseManager::zNew(Command& cmd) {
    int pos_y;
    int pos_x;
    int index = pos_y * _zonesDimension_H + pos_x;
    int zoneID = _ZoneIDGenerator.getUnique();

    _zones[index] = std::make_unique<Zone>(zoneID);
}

