#include "Human.h"
#include <iostream>

Human::Human(std::string name) : name(name) {}
Human::Human() : name("Human") {}

Move* Human::makeMove() {
std::string moveInput;
std::cout << "Enter move: ";
std::cin >> moveInput;
return new Move(moveInput);
}

std::string Human::getName(){
    return name;
}
