#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class StackLinkedList : public AbstractStack<T>{
private:
    Node<T>* head;
    int length;
public:
    StackLinkedList();

    ~StackLinkedList();

    StackLinkedList(const StackLinkedList& other);

    StackLinkedList& operator=(const StackLinkedList& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackLinkedList<T>::StackLinkedList(){
    head = nullptr;
    length = 0;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList(){
    while (!isEmpty()) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) {
        head = nullptr;

        Node<T>* currentOther = other.head;
        Node<T>* lastNewNode = nullptr;

        while (currentOther != nullptr) {
            Node<T>* newNode = new Node<T>{currentOther->data};
;
            if (lastNewNode == nullptr) {
                head = newNode;
            } else {
                lastNewNode->next = newNode;
            }

            lastNewNode = newNode;
            currentOther = currentOther->next;
        }
}

template <typename T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& other) {
        if (this != &other) {
            while (!isEmpty()) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }

            head = nullptr;

            Node<T>* currentOther = other.head;
            Node<T>* lastNewNode = nullptr;

            while (currentOther != nullptr) {
                Node<T>* newNode = new Node<T>{currentOther->data};
;
                if (lastNewNode == nullptr) {
                    head = newNode;
                } else {
                    lastNewNode->next = newNode;
                }

                lastNewNode = newNode;
                currentOther = currentOther->next;
            }
        }
        return *this;
}

template <typename T>
bool StackLinkedList<T>::isEmpty(){
    return head == nullptr;
}

template <typename T>
int StackLinkedList<T>::size(){
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
}

template <typename T>
T& StackLinkedList<T>::top(){
        if (isEmpty()) {
            throw std::out_of_range("Stack empty");
        }

        return head->data;
}

template <typename T>
T StackLinkedList<T>::pop(){
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }

        T e = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
        return e;
}

template <typename T>
void StackLinkedList<T>::push(const T& e){
    Node<T>* newNode = new Node<T>{e};
        head->next = head;
        head = newNode;
        length++;
}


#endif