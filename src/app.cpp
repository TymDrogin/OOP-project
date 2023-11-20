#include "app.hpp"

#define APP_WIDHT 10
#define APP_HEIGHT





App::App() {
}

App& App::instance() {
    static App instance;
    return instance;
}

void App::run() {


}
void App::close() {
    term::Terminal::instance().~Terminal();
}
