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
    for(auto zone : _zones) {
        zone.nextStep();
    }
}

void HouseManager::advance(int steps) {
    for(int i = 0; i < steps; i++) {
        next();
    }
}

