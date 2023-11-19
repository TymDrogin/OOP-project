#pragma once

// App is a heart of a project that puts
// Every part together


class App {
public:
    static App& instance();


private:
    App();
    App(const App&) = delete;
};

