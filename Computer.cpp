#include "Computer.h"
#include <iostream>
    Computer::Computer() : name("Computer"){}

    Move* Computer::makeMove(){
        return new Move("Rock");
    }
    std::string Computer::getName(){
        return name;
    }
