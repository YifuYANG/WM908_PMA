#include "Node.h"

Node::Node() {
    this->data = nullptr;
    this->next=nullptr;
}

Node::Node(Animal* data) {
    this->data = data;
    this->next = nullptr;
}

Animal* Node::getData() {
    return data;
}

void Node::setData(Animal* input) {
    data=input;
}

Node *Node::getNext() {
    return next;
}

void Node::setNext(Node *next1) {
    next = next1;
}
