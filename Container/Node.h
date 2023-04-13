#ifndef PMA_NODE_H
#define PMA_NODE_H


#include "../Components/Characters/Animal.h"

class Node {
private:
    Node* next;
    Animal* data;
public:
    Node();

    Node(Animal* data);

    Animal* getData();

    void setData(Animal* input);

    Node *getNext();

    void setNext(Node *next1);
};


#endif //PMA_NODE_H
