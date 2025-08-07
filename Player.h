#ifndef PLAYER_H
#define PLAYER_H
#include "Move.h"
#include <string>

class Player{
    protected:
        std::string name; // Name of the player
    public:
        std::string getName() {return this-> name;}
        virtual Move* makeMove() = 0; // Pure virtual function for making a move
    };
#endif
