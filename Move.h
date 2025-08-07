#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

class Move {
protected:
    std::string name;
    std::vector<std::string> strongerThan;
public:
    Move(std::string name = "", std::vector<std::string> strongerThan = {}) : name(name), strongerThan(strongerThan) {};
    std::string getName() { return this->name;}
    bool isStrongerThan(Move* other) {
        for (const auto& strongerMove : strongerThan) {
            if (strongerMove == other->getName()) {
                return true;
            }
        }
        return false;
    }
};

#endif
