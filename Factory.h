#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include "Monkey.h"
#include "Robot.h"
#include "Ninja.h"
#include "Zombie.h"
#include "Pirate.h"
#include "Move.h"

class Factory {
public:
    // Factory methods to create objects
    static Move* createObject(std::string type) {
        if (type == "Rock") {
            return new Rock();
        } else if (type == "Scissors") {
            return new Scissors();
        }else if (type == "Paper") {
            return new Paper();
        }else if (type == "Monkey"){
            return new Monkey();
        }else if (type == "Robot"){
            return new Robot();
        }else if (type == "Ninja"){
            return new Ninja();
        }else if (type == "Zombie"){
            return new Zombie();
        }else if (type == "Pirate"){
            return new Pirate();
        }
        return nullptr; // or throw an exception
    }
};
#endif // FACTORY_H