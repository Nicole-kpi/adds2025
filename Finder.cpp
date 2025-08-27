#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    if (s2.empty()) {
        result.push_back(-1);
        return result;
    }

    for (size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(s2.substr(0, i));
        if (found != string::npos) {
            result.push_back(static_cast<int>(found));
        } else {
            result.push_back(-1);

            for (size_t j = i + 1; j <= s2.size(); j++) {
                result.push_back(-1);
            }
            break; 
        }
    }

    return result;
}

