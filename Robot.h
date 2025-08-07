#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

class Robot : public Move {
public:
    Robot() : Move("Robot", {"Ninja", "Zombie"}) {} // Robot beats Ninja and Zombie
};

#endif // ROBOT_H