#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) : head(nullptr){
    if (!array || len <= 0) {
        return;
    }
    Node* tail = nullptr;
    for (int i = 0; i < len; i++) {
        Node* cur = new Node(array[i]);
        if (!head) {
            head = tail = cur;
        } else {
            tail->setLink(cur);
            tail = cur;
        }
    }
}

LinkedList::~LinkedList() {
    Node* head = this->head;
    while(head) {
        Node* n = head->getLink();
        delete head;
        head = n;
    }
    this->head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    //head
    if (!head || pos <= 1){
        newNode->setLink(head);
        head = newNode;
        return;
    }

    //tail
    int len = 1;
    if (pos > len) {
        Node* tail = head;
        while (tail->getLink()) {
            tail = tail->getLink();
            len++;
        }
        if (pos > len) {
            tail->setLink(newNode);
            return;
        }
    }

    Node* prev = head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->getLink();
    }
    newNode->setLink(prev->getLink());
    prev->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (!head || pos <= 1) {
        return false;
    }

    //head
    if (pos == 1) {
        Node* toDelete = head;
        head = head->getLink();
        delete toDelete;
        return true;
    }

    Node* prev = head;
    for (int i = 1; i < pos - 1; i++) {
        if (!prev->getLink()) {
            return false;
        }
        prev = prev->getLink();
    }
    Node* toDelete = prev->getLink();
    if (!toDelete) {
        return false;
    }
    prev->setLink(toDelete->getLink());
    delete toDelete;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return std::numeric_limits<int>::max();
    Node* cur = head;
    for (int i = 1; i < pos; i++) {
        cur = cur->getLink();
        if (!cur) {
            return std::numeric_limits<int>::max();
        }
    }
    return cur->getData();
}

int LinkedList::search(int target) {
    int pos = 1;
    for (Node* cur = head; cur; cur = cur->getLink(), pos++) {
        if (cur->getData() == target) {
            return pos;
        }
    }
    return -1;
}

void LinkedList::printList() {
   if(!head) return;
   std::cout << "[";
   for (Node* cur = head; cur; cur = cur->getLink()) {
       std::cout << cur->getData();
       if (cur->getLink()) {
           std::cout << " ";
       }
   }
   std::cout << "]" << std::endl;
}