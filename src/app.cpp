#include "app.hpp"


App& App::instance() {
    static App instance;
    return instance;
}

App::App() {

}