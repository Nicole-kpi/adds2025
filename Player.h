#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
public:
    virtual char makeMove() = 0;
    virtual std::string getName() const = 0;
    virtual ~Player(); // Virtual destructor for proper cleanup of derived classes
};

#endif