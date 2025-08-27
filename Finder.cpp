#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    vector<string> prefixes(s2.size());
    for (size_t i = 1; i <= s2.size(); i++) {
        prefixes[i - 1] = s2.substr(0, i);
    }

    for(size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(s2.substr(0, i));
    
        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }

    if (!s2.empty()) {
        size_t pos = s1.find(s2);
        while (pos != string::npos) {
            result.push_back(static_cast<int>(pos));
            pos = s1.find(s2, pos + 1);
        }
    }
    
    return result;
}
