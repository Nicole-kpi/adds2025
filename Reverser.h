#ifndef REVERSER_H
#define REVERSER_H
#include <string>

class Reverser {
private:
    std::string reverseStringHelper(const std::string& characters, std::size_t index);
    int reverseDigitHelper(int x, int acc);
    // bool isNegative(int x);
    // bool isZero(int x);

public:
    int reverseDigit(int value);
    std::string reverseString(const std::string& characters);
};
#endif