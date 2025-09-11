#include "BigNumCalc.h"
#include <algorithm>
#include <vector>

std::list<int> BigNumCalc::buildBigNum(const std::string& s) const {
    std::list<int> out;
    if (s.empty()) { out.push_back(0); return out; }
    bool allZeros = true;
    for (char c : s) {
        if (c < '0' || c > '9') continue;   
        int d = c - '0';
        if (d != 0) allZeros = false;
        out.push_back(d);
    }
    if (out.empty() || allZeros) { out.clear(); out.push_back(0); }
    else stripLeadingZeros(out);
    return out;
}

void BigNumCalc::stripLeadingZeros(std::list<int>& num) {
    while (num.size() > 1 && !num.empty() && num.front() == 0) num.pop_front();
    if (num.empty()) num.push_back(0);
}

int BigNumCalc::compare(const std::list<int>& a, const std::list<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size() ? 1 : -1;
    auto ia = a.begin(), ib = b.begin();
    for (; ia != a.end(); ++ia, ++ib) {
        if (*ia != *ib) return *ia > *ib ? 1 : -1;
    }
    return 0;
}

std::list<int> BigNumCalc::add(const std::list<int>& A, const std::list<int>& B) const {
    std::list<int> res;
    auto ia = A.rbegin();
    auto ib = B.rbegin();
    int carry = 0;
    while (ia != A.rend() || ib != B.rend() || carry) {
        int da = (ia != A.rend() ? *ia++ : 0);
        int db = (ib != B.rend() ? *ib++ : 0);
        int s = da + db + carry;
        res.push_front(s % 10);
        carry = s / 10;
    }
    stripLeadingZeros(res);
    return res;
}

std::list<int> BigNumCalc::sub(const std::list<int>& A, const std::list<int>& B) const {
    const std::list<int>* big  = &A;
    const std::list<int>* small= &B;
    if (compare(A, B) < 0) { big = &B; small = &A; }

    std::list<int> res;
    auto ia = big->rbegin();
    auto ib = small->rbegin();
    int borrow = 0;
    while (ia != big->rend()) {
        int da = *ia++ - borrow;
        int db = (ib != small->rend() ? *ib++ : 0);
        if (da < db) { da += 10; borrow = 1; }
        else borrow = 0;
        res.push_front(da - db);
    }
    stripLeadingZeros(res);
    return res;
}

std::list<int> BigNumCalc::mul(const std::list<int>& A, const std::list<int>& B) const {
    if ((A.size() == 1 && A.front() == 0) || (B.size() == 1 && B.front() == 0))
        return std::list<int>{0};

    std::vector<int> a, b;
    a.reserve(A.size()); b.reserve(B.size());
    for (int d : A) a.push_back(d);
    for (int d : B) b.push_back(d);

    std::vector<int> prod(a.size() + b.size(), 0);
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        for (int j = (int)b.size() - 1; j >= 0; --j) {
            int p = (a[i] * b[j]) + prod[i + j + 1];
            prod[i + j + 1] = p % 10;
            prod[i + j] += p / 10;
        }
    }
    std::list<int> res;
    bool leading = true;
    for (int d : prod) {
        if (leading && d == 0) continue;
        leading = false;
        res.push_back(d);
    }
    if (res.empty()) res.push_back(0);
    return res;
}

std::string BigNumCalc::toString(const std::list<int>& num) {
    std::string s;
    s.reserve(num.size());
    for (int d : num) s.push_back(char('0' + d));
    return s;
}
