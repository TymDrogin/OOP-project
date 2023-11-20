// Console smart house simulator
#include "main.hpp"


int main() {

    std::string input = "advance 10";
    Command command(input);
    printTokens(command.getTokens());
    return 0;
}
