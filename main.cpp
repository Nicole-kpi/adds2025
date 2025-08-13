#include <iostream>
#include <string>
#include "Reverser.h"

int main() {
    std::string in;
    if (!(std::cin >> in)) return 0;      
    Reverser r;
    std::cout << r.reverseString(in) << std::endl;
    return 0;
}
