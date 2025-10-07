#include "PrefixMatches.h"

using std::string;

PrefixMatches::PrefixMatches() : root(new Node) {}

PrefixMatches::~PrefixMatches() { delete root; }

int PrefixMatches::bitIndex(char c) {
    if (c == '0') return 0;
    if (c == '1') return 1;
    return -1;
}

void PrefixMatches::insert(const string& address, int routerNumber) {
    Node* cur = root;
    for (char c : address) {
        int b = bitIndex(c);
        if (b == -1) continue;        
        if (!cur->child[b]) cur->child[b] = new Node();
        cur = cur->child[b];
    }
    cur->router = routerNumber;
}

int PrefixMatches::selectRouter(const string& networkAddress) const {
    const Node* cur = root;
    int lastMatch = cur->router;   

    for (char c : networkAddress) {
        int b = bitIndex(c);
        if (b == -1 || !cur || !cur->child[b]) break; 
        cur = cur->child[b];
        if (cur->router != -1) lastMatch = cur->router; 
    }
    return lastMatch; 
}