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

void SinglyLinkedList::DeleteByData(Animal* data) {
    if(head==nullptr){
        cout << "List empty." << endl;
        return;
    }
    if(head->getData()==data){
        head=head->getNext();
        size--;
    }
    Node* temp = head;
    while (temp->getNext()!= nullptr){
        if(temp->getNext()->getData()==data){
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
        cout << temp->getData()->getX()+1 << " X " << temp->getData()->getY()+1 <<endl;
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
    //cout << "Index not found" << endl;
    return false;
}