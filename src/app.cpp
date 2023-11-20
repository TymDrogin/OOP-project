#include "app.hpp"

#define APP_WIDTH 70
#define APP_HEIGHT 25

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

    Window console = Window(0, 0 , trm.getNumCols(), trm.getNumRows(), true);




    getchar();

}
void App::close() {
    //TODO: Autosave?
    term::Terminal::instance().~Terminal();
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

