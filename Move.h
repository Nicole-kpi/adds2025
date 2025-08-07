#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
protected:
    std::string name;
public:
    Move(std::string name);
    virtual ~Move() {}
    std::string getName();
};

#endif
