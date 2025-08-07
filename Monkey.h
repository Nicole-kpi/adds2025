#ifndef MONKEY_H
#define MONKEY_H
#include "Move.h"

class Monkey : public Move {
public:
    Monkey() : Move("Monkey", {"Robot", "Ninja"}) {} // Monkey beats Robot
};
#endif // MONKEY_H