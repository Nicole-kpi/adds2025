#include "Human.h"
#include <iostream>

Human::Human(std::string name): name(name){}

Human::Human() : name("Human") {}

Move* Human::makeMove(){
std::string moveInput;
std::cout << "Enter move: ";
std::cin >> moveInput;

if (!moveInput.empty()) {
        moveInput[0] = std::toupper(moveInput[0]);
        for (size_t i = 1; i < moveInput.length(); ++i) {
            moveInput[i] = std::tolower(moveInput[i]);
        }
    }

return new Move(moveInput);
}

std::string Human::getName(){
    return name;
}
