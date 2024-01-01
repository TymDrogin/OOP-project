#include "app.hpp"


using namespace term;

App::App() {};

App& App::instance() {
    static App instance;
    return instance;
}
void App::run() {

    setTerminalDimensions(APP_WIDTH, APP_HEIGHT);

    Terminal& trm = Terminal::instance();
    
    for(int i=0; i<19; i++) {
        trm.init_color(i, i, 0);
    }

    Window console = Window(0, (APP_HEIGHT * 3) / 4, APP_WIDTH, APP_HEIGHT / 4, true);
    Window logs = Window(APP_WIDTH / 2, 0, APP_WIDTH / 2, (APP_HEIGHT * 3) / 4, true);
    Window housing = Window(0, 0, APP_WIDTH / 2, (APP_HEIGHT * 3) / 4, true);

    HouseManager house;

    int logsWriteCounter = 0;

    while(true) {
        console.clear();
        std::string input;
        console << set_color(0) << "House-sim>>> " << set_color(2) >> input;

        console.clear();

        if(logsWriteCounter > MAX_LOGS_DISPLAYED) {
            logs.clear();
            logsWriteCounter = 0;
        }

        try {
            Command command(input);
            std::string commandTypeString = command.getCommandTypeAsString();

            if (Command(input).isValid()) {
                logs  << set_color(2) << "The command " + commandTypeString + " has been executed." + '\n';
                house.processCommand(Command(input), housing, logs, console);
                logsWriteCounter++;

            } else {
                logs << set_color(1) << "Invalid command!." << '\n';
                logsWriteCounter++;
                displayCommandHint(command, console);
                getchar();
            }
        } catch(const std::logic_error&) {
            logs << set_color(5) << "Invalid symbol has been used, try again.";
            logsWriteCounter++;
        }
    }
}



void App::displayCommandHint(Command& cmd, term::Window& console) {
    std::string commandName = cmd.getTokens()[0].getLexeme();

    auto it = COMMAND_HINTS_LOOKUP.find(commandName);
    console.clear();
    console << set_color(0) << "House-sim>>> ";

    if (it != COMMAND_HINTS_LOOKUP.end()) {
        // Key found in the map, perform logic accordingly
        console << term::set_color(11) << "It appears you where trying to execute: " + commandName << term::set_color(5) <<'\n';
        console << term::set_color(11) << "Correct format is: " << term::set_color(5) << COMMAND_HINTS_LOOKUP.at(commandName);
    } else {
        console << term::set_color(9) << "Please provide correct name of the command to get a hint.";
    }
}

void App::close() {
    Terminal::instance().clear();
}

void App::setTerminalDimensions(int x, int y) {
    // Resizes the terminal. Should be used before calling Terminal::instance()
    // Supports win and linux
    static int callCounter = 0;
#ifdef _WIN32
    if(callCounter < 1) {
        std::system(("mode con: cols=" + std::to_string(x) + " lines=" + std::to_string(y)).c_str());
    }
    callCounter = callCounter + 1;
#else
    if(callCounter < 1) {
        resize_term(APP_WIDTH, APP_HEIGHT);
    }
    callCounter = callCounter + 1;
#endif
}



