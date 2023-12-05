#pragma once

// App is a heart of a project that puts
// Every part together
#include "Constants.hpp"
#include "command.hpp"
#include "../lib/Terminal.h"


using namespace term;

class App {
public:
    static App& instance();
    void run();
    void close();

    // Singleton related functions
    App(const App&) = delete;
    App(App&&) = delete;
    App& operator=(const App&) = delete;
    App& operator=(App&&) = delete;

private:
    App();
    static void setTerminalDimensions(int x, int y);
};

// This class is used to get and operate with the grid of windows used to display
// Rooms in the house. It will be used in a different function.
// I decided to use singleton pattern for this one also because
// Of how portable it is, and also it underlines the use-case of
// This windows
class HousingGrid {
    HousingGrid& instance();

private:
    // Singleton related functions
    HousingGrid();

    HousingGrid(const HousingGrid&) = delete;
    HousingGrid(HousingGrid&&) = delete;
    HousingGrid& operator=(const HousingGrid&) = delete;
    HousingGrid& operator=(HousingGrid&&) = delete;

    // Window storage
    Window _grid[APP_HOUSING_ROWS][APP_HOUSING_COLUMNS];
};