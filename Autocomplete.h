#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>
#include <map>

class TrieNode {
public:
    std::map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
    ~TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::string>& result);

public:
    Autocomplete();
    ~Autocomplete();

    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);
};

#endif
