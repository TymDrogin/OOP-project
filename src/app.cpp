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
    //Window housingGridBorder = Window(0, 0, APP_WIDTH / 2, (APP_HEIGHT * 3) / 4, true);

    Window* housingGrid[APP_HOUSING_ROWS][APP_HOUSING_COLUMNS];

    for (int i = 0; i < APP_HOUSING_ROWS; ++i) {
        for (int j = 0; j < APP_HOUSING_COLUMNS; ++j) {

            //Position calculated using offset from the (0,0), window dimensions and window spacing
            int windowPositionX = APP_HOUSING_OFFSET_X + i *(APP_HOUSING_TILE_WIDTH + APP_HOUSING_TILE_SPACING_X);
            int windowPositionY = APP_HOUSING_OFFSET_Y + j *(APP_HOUSING_TILE_HEIGHT + APP_HOUSING_TILE_SPACING_Y);

            int tileIndex = j * APP_HOUSING_COLUMNS + i;

            housingGrid[i][j] = new Window{windowPositionX,
                                           windowPositionY,
                                           APP_HOUSING_TILE_WIDTH,
                                           APP_HOUSING_TILE_HEIGHT};
            housingGrid[i][j]->operator<<(set_color(tileIndex)).operator<<(tileIndex);
        }
    }










    while(true) {
        console.clear();

        console << set_color(0) << "House-sim>>> ";

        getchar();
        std::string input;
        console << set_color(2) >> input;

        std::string processedInput = Command(input).getCommandTypeAsString();
        console.clear();

        if(Command(input).isValid()) {
            logs << set_color(2) << "Your command type is: " + processedInput + '\n';
        } else {
            logs << set_color(4) << "Your command type is: " + processedInput + '\n';
            console << getchar();
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
    }
    callCounter = callCounter + 1;
#else
    if(callCounter < 1) {
        resize_term(APP_WIDTH, APP_HEIGHT);
    }
    callCounter = callCounter + 1;
#endif
}

