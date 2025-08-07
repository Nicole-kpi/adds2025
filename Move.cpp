#include "Move.h"

Move::Move(std::string name, std::vector<std::string> strongerThan)
    : name(name), strongerThan(strongerThan) {}

std::string Move::getName() const {
    return this->name;
}

bool Move::isStrongerThan(Move* other) const {
    for (const auto& strongerMove : strongerThan) {
        if (strongerMove == other->getName()) {
            return true;
        }
    }
    return false;
}
