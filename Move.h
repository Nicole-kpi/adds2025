#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

class Move {
protected:
    std::string name;
    std::vector<std::string> strongerThan;

public:
    Move(std::string name = "", std::vector<std::string> strongerThan = {});
    std::string getName() const;
    bool isStrongerThan(Move* other) const;
};

#endif