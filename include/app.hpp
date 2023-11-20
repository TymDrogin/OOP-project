#pragma once

// App is a heart of a project that puts
// Every part together
#include "command.hpp"
#include "../lib/Terminal.h"





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

    term::Window ;
};

