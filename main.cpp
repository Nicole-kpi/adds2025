#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"
using namespace std;

int main() {
    Autocomplete ac;
    ac.insert("ball");
    ac.insert("ballet");
    ac.insert("bin");

    cout << "Autocomplete test:\n";
    for (auto &s : ac.getSuggestions("bal")) cout << s << " ";
    cout << "\n";

    PrefixMatches pm;
    pm.insert("1100110111", 1);
    pm.insert("110011011", 2);
    pm.insert("1100110", 3);
    cout << "Router: " << pm.selectRouter("110011011001") << endl;

    return 0;
}