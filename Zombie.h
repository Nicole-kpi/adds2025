#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
public:
    Zombie() : Move("Zombie", {"Monkey", "Pirate"}) {} // Zombie beats Monkey and Robot
};
#endif // ZOMBIE_H