#ifndef PLAYER_H
#define PLAYER_H
#include "Move.h"
#include <string>

class Player{
    public:
        virtual std::string getName() = 0;
        virtual Move* makeMove() = 0; // Pure virtual function for making a move
        virtual ~Player();
};
#endif
