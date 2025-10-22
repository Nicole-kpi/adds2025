#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronId);
    int search(std::string name);
    bool borrowDocument(int docId, int patronId);
    void returnDocument(int docId, int patronId);
private:
    struct Doc {
        int id = 0;
        int license_limit = 0;
        int in_use = 0;
        std::unordered_set<int> borrowers;
    };

    std::unordered_map<std::string, int> name_to_id_;
    std::unordered_map<int, Doc> docs_;
    std::unordered_set<int> patrons_;

    bool hasPatron_(int patronID) const { return patrons_.find(patronID) != patrons_.end(); }
    bool hasDocId_(int docid)   const { return docs_.find(docid) != docs_.end(); }

};

#endif // DOCUMENTMANAGER_H