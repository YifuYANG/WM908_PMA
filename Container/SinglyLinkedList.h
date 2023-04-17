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

    void setHead(Node *head);

    void printList();

    Node* getByXY(int x, int y);

    void setSize(int size);
};


#endif //PMA_SINGLYLINKEDLIST_H
