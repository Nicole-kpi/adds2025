#ifndef Pirate_H
#define Pirate_H
#include "Move.h"
class Pirate : public Move {
public:
    Pirate() : Move("Pirate", {"Monkey", "Robot"}) {} // Pirate beats Monkey and Robot
};
#endif // Pirate_H