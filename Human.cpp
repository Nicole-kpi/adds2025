#include "Human.h"
#include <iostream>
#include "Factory.h"

Human::Human(std::string name){
    this->name = name;
}

Move *Human::makeMove()
{
    std::string moveInput;
    //std::cout << "Enter move: ";
    std::cin >> moveInput;
    Factory factory;
    return Factory::createObject(moveInput);
}