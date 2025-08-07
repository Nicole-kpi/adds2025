#include "Computer.h"
#include "Factory.h"

Computer::Computer() {
    name = "Computer"; 
}

Move* Computer::makeMove() {
    return Factory::createObject("Rock");
}