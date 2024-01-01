#include "houseManager.hpp"
/* Public */

HouseManager::HouseManager() {};
void HouseManager::processCommand(Command cmd,
                                  term::Window& housing,
                                  term::Window& logs,
                                  term::Window& console) {
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
            zLista(housing);
            break;
// -------Commands to manage zones and their content-------
        case CommandType::Zcomp:
            zComp(cmd);
            break;
        case CommandType::Zprops:
            zProps(cmd, logs);
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
// ------    void displayCommandHint(term::Window& console);-Commands for copying/retrieving rule processors--------

// -------Additional general commands--------
        case CommandType::Exec:
            exec(cmd, housing, logs, console);
            break;

        default:
            break;


    }
}

void HouseManager::displayZonesData(term::Window& win) {
    win.clear();
    for (auto &zone : _zones) {
        win << term::set_color(2) << "ID: " << zone->getID()           << term::set_color(0) << ", ";
        win << term::set_color(3) << "Sens: "<< zone->getNumSensors() << term::set_color(0) << ", ";
        win << term::set_color(4) << "Rules: "<< zone->getNumRules()   << term::set_color(0) << ", ";
        win << term::set_color(5) << "Devices: "<< zone->getNumDevices();

        win << '\n';
    }
};
void HouseManager::displayZoneProps(term::Window& win, int ID) {
    win.clear();
    for(auto &zone : _zones) {
        if(zone->getID() == ID) {
            win << term::set_color(14) << "Props of the zone with ID " << ID << ":"<<  '\n';
            win << term::set_color(2) << "Temp: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Temperature) << '\n';
            win << term::set_color(3) << "Light: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Light) << '\n';
            win << term::set_color(4) << "Radiation: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Radiation) << '\n';
            win << term::set_color(5) << "Vibration: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Vibration) << '\n';
            win << term::set_color(6) << "Humidity: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Humidity) << '\n';
            win << term::set_color(10) << "Smoke: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Smoke) << '\n';
            win << term::set_color(9) << "Sound: " << term::set_color(7) << zone->getZoneProps().at(PropertyType::Sound) << '\n';
            break;
        }
    }
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
    _zonesDimension_H = std::stoi(cmd.getTokens()[1].getLexeme());
    _zonesDimension_W = std::stoi(cmd.getTokens()[2].getLexeme());

    // Checks if both of dimensions are in bounds or set them to corresponding default value
    _zonesDimension_H = std::clamp(_zonesDimension_H, HOUSE_MANAGER_MIN_ROOMS_DIMENSION, HOUSE_MANAGER_MAX_ROOMS_DIMENSION);
    _zonesDimension_W = std::clamp(_zonesDimension_W, HOUSE_MANAGER_MIN_ROOMS_DIMENSION, HOUSE_MANAGER_MAX_ROOMS_DIMENSION);

    _zones.clear();
    for (int i = 0; i < _zonesDimension_W * _zonesDimension_H; i++) {
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
void HouseManager::zLista(term::Window& win) {
    displayZonesData(win);
}

void HouseManager::zComp(Command &cmd) {

}

void HouseManager::zProps(Command &cmd, term::Window& win) {
    int ID = std::stoi(cmd.getTokens()[1].getLexeme());
    displayZoneProps(win, ID);
}

void HouseManager::pMod(Command &cmd) {

}

void HouseManager::cNew(Command &cmd) {

}

void HouseManager::cRem(Command &cmd) {

}

void HouseManager::rNew() {

}

void HouseManager::pMuda() {

}

void HouseManager::rLista() {

}

void HouseManager::rRem() {

}

void HouseManager::aSoc() {

}

void HouseManager::aDes() {

}

bool HouseManager::aCom() const {
    return false;
}

void HouseManager::pSalva() {

}

void HouseManager::pRepoe() {

}

void HouseManager::pRem() {

}

void HouseManager::pLista() {

}

// -------Commands to manage zones and their content-------expression






// -------Additional general commands--------
void HouseManager::exec(Command& cmd, term::Window& housing, term::Window& logs, term::Window& console) {
    std::string filename = cmd.getTokens()[1].getLexeme();

    CommandFromFile commands = CommandFromFile(filename);
    if(commands.isValid()) {
        for (auto cmd : commands.getCommands()) {
            processCommand(cmd, housing, logs, console);
        }
    } else {
        logs << term::set_color(1) << "Invalid command file has been passed!";
    }
}














