#include "Referee.h"
#include <iostream>

Referee::Referee() {}

bool beats(const std::string& move1, const std::string& move2) {
    if (move1 == "Rock" && move2 == "Scissors") return true;
    if (move1 == "Scissors" && move2 == "Paper") return true;
    if (move1 == "Paper" && move2 == "Rock") return true;
    return false;
}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    std::string m1 = move1->getName();
    std::string m2 = move2->getName();

    //std::cout << player1->getName() << " " << player2->getName() << " " << m1 << " " << m2 << std::endl;

    Player* winner = nullptr;

    if (m1 == m2) {
        std::cout << "It's tie" << std::endl;
    } else if (beats(m1, m2)) {
        winner = player1;
        std::cout << "Winner: " << winner->getName() << std::endl;
    } else {
        winner = player2;
        std::cout << "Winner: " << winner->getName() << std::endl;
    }

    delete move1;
    delete move2;
    return winner;
}

