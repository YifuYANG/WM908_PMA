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

void SinglyLinkedList::DeleteByIndex(int index) {
    if(head==nullptr){
        cout << "List empty." << endl;
        return;
    }
    if(head->getData()->getIndex()==index){
        head=head->getNext();
        size--;
    }
    Node* temp = head;
    while (temp->getNext()!= nullptr){
        if(temp->getNext()->getData()->getIndex()==index){
            temp->setNext(temp->getNext()->getNext());
            size--;
            return;
        } else {
            temp=temp->getNext();
        }
    }
}

void SinglyLinkedList::ReplaceByIndex(int index, Animal* data) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getData()->getIndex() == index) {
            temp->setData(data);
            return;
        }
        temp = temp->getNext();
    }
    cout << "Data not found" << endl;
}


void SinglyLinkedList::printList() {
    Node* temp = head;
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != nullptr) {
        cout <<"Index -> "<< temp->getData()->getIndex()<<" holds ->";
        cout << temp->getData()->getX() << " X " << temp->getData()->getY();
        cout<<" moved or not: "<<temp->getData()->isWhetherThisAnimalHasMovedOrNot()<<endl;
        temp = temp->getNext();
    }
}

Node *SinglyLinkedList::getByIndex(int index) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getData()->getIndex() == index) {
            return temp;
        }
        temp = temp->getNext();
    }
    cout << "Index not found" << endl;
    return nullptr;
}

bool SinglyLinkedList::checkByIndex(int index) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getData()->getIndex() == index) {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

Node* SinglyLinkedList::getByXY(int x, int y) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getData()->getX() == x && temp->getData()->getY() == y) {
            return temp;
        }
        temp = temp->getNext();
    }
    cout << "Index not found" << endl;
    return nullptr;
}
