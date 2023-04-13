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

    void DeleteByData(Animal* data);

    void printList();

    void ReplaceByData(Animal* oldData, Animal* newData);

    Node* getByIndex(int index);
};


#endif //PMA_SINGLYLINKEDLIST_H
