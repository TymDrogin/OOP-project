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
    
    for(int i=1; i<25; i++) {
        trm.init_color(i, i, 0);
    }

    Window console = Window(0, (APP_HEIGHT * 3) / 4, APP_WIDTH, APP_HEIGHT / 4, true);
    Window logs = Window(APP_WIDTH / 2, 0, APP_WIDTH / 2, (APP_HEIGHT * 3) / 4, true);
    Window housing = Window(0, 0, APP_WIDTH / 2, (APP_HEIGHT * 3) / 4, true);

    while(true) {
        console.clear();

        console << set_color(0) << "House-sim>>> ";

        getchar();
        std::string input;
        console << set_color(2) >> input;

        std::string processedInput = Command(input).getCommandTypeAsString();
        console.clear();

        if(Command(input).isValid()) {
            if(processedInput == "exit") {
                App::instance().close();
            }

            console << set_color(2) << "Your command type is: " + processedInput + '\n';
            getchar();
        } else {
            console << set_color(4) << "Your command type is: " + processedInput + '\n';
            getchar();
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
    }
    callCounter = callCounter + 1;
#else
    if(callCounter < 1) {
        resize_term(APP_WIDTH, APP_HEIGHT);
    }
    callCounter = callCounter + 1;
#endif
}

