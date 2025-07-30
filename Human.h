#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class Human : public Player {
private:
    string name;
public:
    Human();
    char makeMove() override;
    string getName() const override;
};
#endif
 

