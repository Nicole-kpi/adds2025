#include "Node.h"

Node::Node(int d, Node* n) : data(d), link(n) {}

int Node::getData() const {
    return data;
}
void Node::setData(int d) {
    data = d;
}

Node* Node::getLink() const {
    return link;
}
void Node::setLink(Node* n) {
    link = n;
}