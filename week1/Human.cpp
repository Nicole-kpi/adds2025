#include "Human.h"
#include <iostream>
#include <string>

using namespace std;

Human::Human() {
    cout << "Enter your name: ";
    getline(cin, name);
}

char Human::makeMove() {
    char move;
    cout << "Enter move (R, P, S): ";
    cin >> move;
    return move;
}

string Human::getName() const {
    return name;
}


