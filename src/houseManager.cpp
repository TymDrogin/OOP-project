#include "houseManager.hpp"
/* Public */
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
            hNova(cmd);
            break;
    }
}
void HouseManager::processCommandsFromFile(CommandFromFile cmd) {
    for (auto command : cmd.getCommands()) {
        processCommand(command);
    }
}
void HouseManager::displayData(term::Window &window) const {

}


int HouseManager::getZoneIndex(int posX, int posY) {
    return posY * _zonesDimension_H + posX;
}



// -------Commands for simulated time-------
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

// -------Commands for managing housing and zones------
void HouseManager::hNova(Command &cmd) {
    int rows = std::stoi(cmd.getTokens()[1].getLexeme());
    int columns = std::stoi(cmd.getTokens()[2].getLexeme());

    _zones.clear();
    for (int i = 0; i < rows * columns; i++) {
        int zoneID = _ZoneIDGenerator.getUnique();
        _zones.emplace_back(std::make_unique<Zone>(zoneID));
    }
}
void HouseManager::hRem() {
    _zones.clear();
}
void HouseManager::zNew(Command& cmd) {
    int posY = std::stoi(cmd.getTokens()[1].getLexeme());
    int posX = std::stoi(cmd.getTokens()[2].getLexeme());
    
    int index = getZoneIndex(posX, posY);
    int zoneID = _ZoneIDGenerator.getUnique();

    _zones[index] = std::make_unique<Zone>(zoneID);
}

void HouseManager::zRem(Command &cmd) {
    int zoneID = std::stoi(cmd.getTokens()[1].getLexeme());

    for(int i = 0; i < _zones.size(); i++) {
        // If the zone with this id is found delete it and put the empty one
        // On its place
        if(_zones[i]->getID() == zoneID) {
            int emptyZoneID = _ZoneIDGenerator.getUnique();
            _zones[i] = std::make_unique<Zone>(emptyZoneID);
            break;
        }
    }
}
// -------Commands to manage zones and their content-------







