#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
}

void SinglyLinkedList::Insert(Animal* data) {
    Node* newNode= new Node(data);
    if(head== nullptr){
        head=newNode;
        size++;
        return;
    }
    Node* temp=head;
    while(temp->getNext() != nullptr){
        temp=temp->getNext();
    }
    temp->setNext(newNode);
    size++;
}

int SinglyLinkedList::GetSize() {
    return size;
}


void SinglyLinkedList::printList() {
    Node* temp = head;
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << temp->getData()->getX() << " X " << temp->getData()->getY();
        cout<<" character: "<<temp->getData()->getCharacter();
        cout<<" HP: "<<temp->getData()->getHp()<<endl;
        temp = temp->getNext();
    }
}


Node* SinglyLinkedList::getByXY(int x, int y) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getData()->getX() == x && temp->getData()->getY() == y) {
            return temp;
        }
        temp = temp->getNext();
    }

    cout << "XY not found: " <<x<<" X "<<y<<endl;
    return nullptr;
}

Node *SinglyLinkedList::getHead() {
    return head;
}