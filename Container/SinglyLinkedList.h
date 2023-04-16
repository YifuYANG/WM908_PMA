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

    void DeleteByXY(int x, int y);

    void printList();

    Node* getByXY(int x, int y);

    Node* getByIndex(int index);

    bool checkByIndex(int index);
};


#endif //PMA_SINGLYLINKEDLIST_H
