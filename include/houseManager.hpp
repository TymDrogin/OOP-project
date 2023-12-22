#pragma once

#include "sensor.hpp"
#include "command.hpp"
#include "ruleProcessor.hpp"
#include "zone.hpp"
#include "utils.hpp"

#include "../lib/Terminal.h"


class HouseManager {
public:
    void processCommand(Command cmd);
    void processCommandsFromFile(CommandFromFile cmd);


    void displayData(term::Window& window) const;

private:
    std::vector<std::unique_ptr<Zone>> _zones;
    IDGenerator _ZoneIDGenerator;

    int getZoneIndex(int posX, int posY);

    int _zonesDimension_W, _zonesDimension_H;

    // -------Commands for simulated time-------
    void next();
    void advance(Command& cmd);

    // -------Commands for managing housing and zones------

    void hNova(Command& cmd);
    void hRem(); // uses destructor for all the parts of house
    void zNew(Command& cmd); // creates new zone in the position
    void zRem(Command& cmd);
    void zLista(); //TODO: Connect to logs

    // -------Commands to manage zones and their content-------
    void zComp(Command& cmd); // TODO: Connect to logs
    void zProps(Command& cmd); // TODO: Connect to logs
    void pMod(Command& cmd); //
    void cNew(Command& cmd); //TODO: Have to finish this validation
    void cRem(Command& cmd);

    // -------Commands for rule processors-------
    void rNew();
    void pMuda();
    void rLista();
    void rRem();
    void aSoc();
    void aDes();

    // -------Commands to interact with devices-------
    bool aCom() const;

    // -------Commands for copying/retrieving rule processors--------

    void pSalva();
    void pRepoe();
    void pRem();
    void pLista();
};

