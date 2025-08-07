#include "Move.h"

Move::Move(std::string name) : name(name) {}
std::string Move::getName() {
    return name;
}
