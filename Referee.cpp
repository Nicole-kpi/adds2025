#include "Referee.h"
#include <iostream>

Referee::Referee() {}
Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    Player* winner = nullptr;

    if (move1->isStrongerThan(move2)) {
        winner = player1;
        //std::cout << "Winner: " << winner->getName()  << std::endl;
    } else if (move2->isStrongerThan(move1)) {
        winner = player2;
        //std::cout << "Winner: " << winner->getName() << std::endl;
    }
    return winner;
}

