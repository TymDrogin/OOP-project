#include "app.hpp"

#define APP_WIDTH 70
#define APP_HEIGHT 24

using namespace term;

App::App() {};

App& App::instance() {
    static App instance;
    return instance;
}



void App::run() {

    setTerminalDimensions(APP_WIDTH, APP_HEIGHT); // resize the CMD

    Terminal& trm = Terminal::instance();
    for(int i=1; i<25; i++) {
        trm.init_color(i, i, 0);
    }

    Window console = Window(0, (APP_HEIGHT * 3) / 4, APP_WIDTH, APP_HEIGHT / 4, true);

    while(true) {
        console.clear();

        console << set_color(0) << "House-sim>>> ";

        std::string input;
        console << set_color(2) >> input;

        std::string processedInput = Command(input).getCommandTypeAsString();
        console.clear();

        if(Command(input).isValid()) {
            console << set_color(2) << "Your command type is: " + processedInput;
            getchar();
        } else {
            console << set_color(4) << "Your command type is: " + processedInput;
            getchar();
        }

        if(processedInput == "exit") {
            App::instance().close();
        }
    }
}
void App::close() {
    //TODO: Autosave?
}

void App::setTerminalDimensions(int x, int y) {
    // Resizes the terminal. Should be used before calling Terminal::instance()
    // Supports win and linux


    static int callCounter = 0;
#ifdef _WIN32
    if(callCounter < 1) {
        std::system(("mode con: cols=" + std::to_string(x) + " lines=" + std::to_string(y)).c_str());
        callCounter = callCounter + 1;
    }
#else
    if(callCounter < 1) {
        std::string escapeSequence = "'\'e[8;" + std::to_string(x) + ";" + std::to_string(y) + "t";
        td::cout << escapeSequence << std::endl;
        callCounter = callCounter + 1;
    }
#endif
}

