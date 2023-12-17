#include "utils.hpp"

int IDGenerator::getUnique() {
    static int currentId = -1;
    currentId = currentId + 1;
    return currentId;
}