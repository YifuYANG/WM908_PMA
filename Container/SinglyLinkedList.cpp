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

void SinglyLinkedList::DeleteByXY(int x, int y) {
    if(head==nullptr){
        cout << "List empty." << endl;
        return;
    }
    if(head->getData()->getX()==x && head->getData()->getX()==y){
        head=head->getNext();
        Node* temp = head;
        size--;
        while (temp != nullptr) {
            temp->getData()->setIndex(temp->getData()->getIndex()-1);
            temp = temp->getNext();
        }
    }
    Node* temp = head;
    while (temp->getNext()!= nullptr){
        if(temp->getNext()->getData()->getX()==x && temp->getNext()->getData()->getY()==y){
            temp->setNext(temp->getNext()->getNext());
            cout<<"So=izeO:: "<<size<<endl;
            size--;
            temp=temp->getNext();
            while (temp != nullptr) {
                temp->getData()->setIndex(temp->getData()->getIndex()-1);
                temp = temp->getNext();
            }
            return;
        } else {
            temp=temp->getNext();
        }
    }
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
        cout<<" character: "<<temp->getData()->getCharacter();
        cout<<" HP: "<<temp->getData()->getHp()<<endl;
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

    cout << "XY not found: " <<x<<" X "<<y<<endl;
    return nullptr;
}

Node *SinglyLinkedList::getHead() {
    return head;
}