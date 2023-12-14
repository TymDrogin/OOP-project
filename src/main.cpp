// Console smart house simulator
#include "main.hpp"

int main() {

    std::string filename = "cmd1.txt";
    std::ifstream File(filename);

    if(!File.is_open()) {
        std::cout << "file is not okay";
    } else {
        std::cout << "File is okay";
    }
    auto commands = CommandFromFile(filename).getCommandsTypesAsStrings();
    std::cout << std::endl;
    for(auto command : commands) {
        std::cout << command << std::endl;
    }
    //App::instance().run();
}
