#include "Computer.h"
#include <iostream>
    Computer::Computer() : name("Computer"){}

    Move* Computer::makeMove(){
        return new Move("Robot");
    }
    std::string Computer::getName(){
        return name;
    }
