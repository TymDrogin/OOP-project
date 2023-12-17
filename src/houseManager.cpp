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

