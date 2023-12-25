#include "houseManager.hpp"
/* Public */

HouseManager::HouseManager(term::Window &logs, term::Window &housing) : _logsWindow(logs), _housingWindow(housing) {};




void HouseManager::processCommand(Command cmd) {
    // If invalid command has been sent exeption
    if(!cmd.getCommandType()) {
        throw std::logic_error("Invalid command has been passed to the manager");
    }

    CommandType cmdType = cmd.getCommandType().value();

    switch (cmdType) {
// -------Commands for simulated time-------
        case CommandType::Next:
            next();
            break;
        case CommandType::Advance:
            advance(cmd);
            break;

// -------Commands for managing housing and zones------
        case CommandType::Hnova:
            hNova(cmd);
            break;
        case CommandType::Hrem:
            hRem();
            break;
        case CommandType::Znew:
            zNew(cmd);
            break;
        case CommandType::Zrem:
            zRem(cmd);
            break;
        case CommandType::Zlista:
            zLista();
            break;
// -------Commands to manage zones and their content-------
        case CommandType::Zcomp:
            zComp(cmd);
            break;
        case CommandType::Zprops:
            zProps(cmd);
            break;
        case CommandType::Pmod:
            pMod(cmd);
            break;
        case CommandType::Cnew:
            cNew(cmd);
            break;
        case CommandType::Crem:
            cRem(cmd);
            break;

// -------Commands for rule processors------
// -------Commands to interact with devices-------
// -------Commands for copying/retrieving rule processors--------



    }
}
void HouseManager::processCommandsFromFile(CommandFromFile cmd) {
    for (auto command : cmd.getCommands()) {
        processCommand(command);
    }
}
void HouseManager::displayData() const {
  for(int rows = 0; rows < _zonesDimension_W; rows++){



      for(int columns = 0; columns < _zonesDimension_H; columns++) {

      }
  }
};


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
void HouseManager::zLista() {}

// -------Commands to manage zones and their content-------







