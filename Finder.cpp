#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    if (s2.empty()) return result;

    string prefix;
    prefix.reserve(s2.size()); 

    for (size_t i = 0; i < s2.size(); i++) {
        prefix.push_back(s2[i]);   
        size_t found = s1.find(prefix);
        if (found != string::npos) {
            result.push_back(static_cast<int>(found));
        } else {
            result.push_back(-1);
        }
    }
    return result;
}


