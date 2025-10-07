#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>

class PrefixMatches{
private:
    struct Node{
        Node* child[2];
        int router;
        Node() : child{nullptr, nullptr}, router(-1) {}
        ~Node(){
            delete child[0];
            delete child[1];
        }
    };

    Node* root;
    static int bitIndex(char c);

public:
    PrefixMatches();
    ~PrefixMatches();
    void insert(const std::string& address, int routerNuber);
    int selectRouter(const std::string& networkAddress) const;
};
#endif