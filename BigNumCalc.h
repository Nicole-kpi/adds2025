#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class BigNumCalc {
public:
    BigNumCalc() = default;
    ~BigNumCalc() = default;

    // "12345" -> {1,2,3,4,5}
    std::list<int> buildBigNum(const std::string& numString) const;

    std::list<int> add(const std::list<int>& num1, const std::list<int>& num2) const;
    std::list<int> sub(const std::list<int>& num1, const std::list<int>& num2) const; 
    std::list<int> mul(const std::list<int>& num1, const std::list<int>& num2) const;

    static std::string toString(const std::list<int>& num);

private:
    static void stripLeadingZeros(std::list<int>& num);
    static int  compare(const std::list<int>& a, const std::list<int>& b); // a>b:1, a==b:0, a<b:-1
};

#endif // BIGNUMCALC_H
