#include <iostream>
#include <string>
#include <list>
#include "BigNumCalc.h"

int main() {
        std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, op, b;
    if (!(std::cin >> a >> op >> b)) return 0;

    bigNumCalc calc;
    auto A = calc.buildBigNum(a);
    auto B = calc.buildBigNum(b);

    std::list<int> ans;
    if (op == "+")       ans = calc.add(A, B);
    else if (op == "-")  ans = calc.sub(A, B);   // 返回非负差
    else if (op == "*")  ans = calc.mul(A, B);
    else return 0; // 不支持的运算符，静默退出

    std::cout << bigNumCalc::toString(ans) << '\n';
    return 0; 
}