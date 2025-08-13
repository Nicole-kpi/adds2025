#include "Reverser.h"
#include <algorithm>

using namespace std;

int Reverser::reverseDigit(int value){
    if (value < 0) return -1;
    return reverseDigitHelper(value, 0); 
}

int Reverser::reverseDigitHelper(int x, int acc){
    if (x == 0) return acc;
    return reverseDigitHelper(x / 10, acc * 10 + x % 10);
}

string Reverser::reverseString(const string& characters){
    if (characters.empty()) return "EORROR";
    return reverseStringHelper(characters, characters.size());
}

string Reverser::reverseStringHelper(const string& characters, size_t index){
    if (index == 0) return std::string();
    return reverseStringHelper(characters, index + 1) + characters[index];
}

