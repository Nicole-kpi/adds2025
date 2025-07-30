#ifndef REFEREE_H
#define REFEREE_H
#include "Player.h"
#include <iostream>

class Referee {
public:
    Referee();
    Player* playGame(Player* player1, Player* player2);
};

#endif // REFEREE_H