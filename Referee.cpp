#include "Referee.h"
#include <iostream>

Referee::Referee() {}

bool beats(const std::string& move1, const std::string& move2) {
    if (move1 == "Monkey" && (move2 == "Ninja" || move2 == "Robot")) return true;
    if (move1 == "Robot"  && (move2 == "Ninja" || move2 == "Zombie")) return true;
    if (move1 == "Pirate" && (move2 == "Robot" || move2 == "Monkey")) return true;
    if (move1 == "Ninja"  && (move2 == "Pirate" || move2 == "Zombie")) return true;
    if (move1 == "Zombie" && (move2 == "Pirate" || move2 == "Monkey")) return true;
    return false;
}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    std::string m1 = move1->getName();
    std::string m2 = move2->getName();

    Player* winner = nullptr;

    if (m1 == m2) {
        std::cout << "It's a tie!" << std::endl;
    } else if (beats(m1, m2)) {
        winner = player1;
        std::cout  << "Winner: " << winner->getName() << std::endl;
    } else {
        std::cout << "Invalid move(s)." << std::endl;
    }

    delete move1;
    delete move2;
    return winner;
}

