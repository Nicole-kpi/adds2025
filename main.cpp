#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>
using namespace std;

int main() {
    Human human;
    Computer computer;
    Referee referee;

    Player* winner = referee.refGame(&human, &computer); 

    if (winner == nullptr)
        // cout << "It's a Tie." << std::endl;
    else
        cout << winner->getName() << endl;

    return 0;
}
