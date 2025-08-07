#ifndef NINJIA_H
#define NINJIA_H

#include "Move.h"

class Ninja : public Move {
public:
    Ninja() : Move("Ninja", {"Pirate", "Zombie"}) {} // Ninja beats Pirate and Zombie
};
#endif // NINJIA_H