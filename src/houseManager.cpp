#include "houseManager.hpp"

void HouseManager::processCommand(Command cmd) {
    // If invalid command has been send exeption
    if(!cmd.getCommandType()) {
        throw std::logic_error("Invalid command has been passed to the manager");
    }

    CommandType cmdType = cmd.getCommandType().value();

}

void HouseManager::processCommandsFromFile(CommandFromFile cmdFromFile) {

}

void HouseManager::advance() {

}

void HouseManager::hRem() {

}

void HouseManager::zNew() {

}
