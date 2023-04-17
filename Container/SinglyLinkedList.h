#ifndef PMA_SINGLYLINKEDLIST_H
#define PMA_SINGLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;
class SinglyLinkedList {
private:
    int size=0;
    Node* head;
public:
    SinglyLinkedList();

    void Insert(Animal* data);

    int GetSize();

    Node* getHead();

    void printList();

    Node* getByXY(int x, int y);
};


#endif //PMA_SINGLYLINKEDLIST_H
