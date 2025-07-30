#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>

using namespace std;

int main(){
    Human human;
    Computer computer;
    Referee referee;

    Player* winner = referee.playGame(&human, &computer);
    if (winner != nullptr) {
        cout << winner->getName() << " Wins." << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}