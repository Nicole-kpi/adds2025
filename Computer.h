#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include <string>

class Computer : public Player {
private:
    std::string name;
public:
    Computer();
    char makeMove() override;
    std::string getName() const override;
};
#endif // COMPUTER_H