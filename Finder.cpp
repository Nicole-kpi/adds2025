#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    if (s2.empty()) return result;

    size_t pos = s1.find(s2); 
    while (pos != string::npos) {
        result.push_back(static_cast<int>(pos));
        pos = s1.find(s2, pos + 1); 
    }

    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
}

