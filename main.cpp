#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>

int main(){
    Player* player1 = new Human("Player1");
    Player* player2 = new Computer();

    Referee ref;
    Player* winner = ref.refGame(player1, player2);
    delete player1;
    delete player2;
    return 0;
}