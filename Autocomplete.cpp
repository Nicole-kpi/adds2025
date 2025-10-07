#include "Autocomplete.h"

TrieNode::TrieNode() {
    isEndOfWord = false;
}

TrieNode::~TrieNode() {
    for (auto& pair : children)
        delete pair.second;
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    delete root;
}

void Autocomplete::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end())
            current->children[c] = new TrieNode();
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

void Autocomplete::dfs(TrieNode* node, const std::string& prefix, std::vector<std::string>& result) {
    if (node->isEndOfWord)
        result.push_back(prefix);
    for (auto& pair : node->children)
        dfs(pair.second, prefix + pair.first, result);
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) {
    TrieNode* current = root;
    std::vector<std::string> result;
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end())
            return result;
        current = current->children[c];
    }
    dfs(current, partialWord, result);
    return result;
}