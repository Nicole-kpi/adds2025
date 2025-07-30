#include <iostream>
#include "Computer.h"

using namespace std;
Computer::Computer() : name("Computer") {
    // Constructor initializes the computer player with a default name
}
char Computer::makeMove() {
    // only can move R
    //cout << "Computer is making a move..." << endl;
    return 'R'; // Computer always plays Rock

}
string Computer::getName() const {
    return name; // Returns the name of the computer player
}
