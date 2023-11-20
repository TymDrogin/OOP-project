// Console smart house simulator
#include "main.hpp"


int main() {

    std::string input = "advance 20 20";
    Command command(input);
    printTokens(command.getTokens());
    return 0;
}
