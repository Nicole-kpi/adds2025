#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    name_to_id_[name] = id;
    Doc &d = docs_[id];
    d.id = id;
    d.license_limit = license_limit;
}

void DocumentManager::addPatron(int patronID) {
    patrons_.insert(patronID);
}

int DocumentManager::search(std::string name) {
    auto it = name_to_id_.find(name);
    if (it == name_to_id_.end()) return 0;  
    return it->second;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto dit = docs_.find(docid);
    if (dit == docs_.end()) return false;
    if (!hasPatron_(patronID)) return false;

    Doc &doc = dit->second;
    if (doc.borrowers.find(patronID) != doc.borrowers.end()) return false;
    if (doc.in_use >= doc.license_limit) return false;

    doc.borrowers.insert(patronID);
    ++doc.in_use;
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto dit = docs_.find(docid);
    if (dit == docs_.end()) return;          
    Doc &doc = dit->second;

    auto bit = doc.borrowers.find(patronID);
    if (bit == doc.borrowers.end()) return;   

    doc.borrowers.erase(bit);
    if (doc.in_use > 0) --doc.in_use;         
}
