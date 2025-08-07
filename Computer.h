#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include <string>
class Computer : public Player{
private:
    std::string name;
public:
    Computer();
    Move* makeMove();
    std::string getName() override;
};
#endif