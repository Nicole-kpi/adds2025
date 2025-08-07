#include "Computer.h"
#include "Factory.h"
#include <iostream>
    Computer::Computer() : name("Computer"){}

    Move* Computer::makeMove(){
        Factory factory;
        return factory.createObject("Rock"); // For simplicity, always return Rock
    }
