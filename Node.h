#ifndef NODE_H
#define NODE_H

#include <string>
class Node {
private:
    int data;
    Node* link;

public:
    Node(int d = 0, Node* n = nullptr);
    int getData() const;
    void setData(int d);

    Node* getLink() const;
    void setLink(Node* n);
};

#endif // NODE_H