#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
using namespace std;

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque();
	Deque(const Deque& other); 
	Deque& operator=(const Deque& other); 
	~Deque();
	bool isEmpty();
	int size();
	Type first();
	Type last();
	void insertFirst(Type o);
	void insertLast(Type o);
	Type removeFirst();
	Type removeLast();
};

// Your implementation here 

template <class Type>
Deque<Type>::Deque() {
	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;
	
}

template <class Type>
Deque<Type>::~Deque() {
	while(!isEmpty()) 
	{
		Node<Type>* tempNode = firstNode;
		firstNode = firstNode->getNext();
		delete tempNode;
		s--;
	}
	firstNode = nullptr;
	lastNode = nullptr;
}

template <class Type>
Deque<Type>::Deque(const Deque& other) {
	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;
	Node<Type>* currNode = other.firstNode;
	Node<Type>* prevNode = nullptr;

	while (currNode != nullptr) {
		Node<Type>* newNode = new Node<Type>{currNode->getData()};
		if (prevNode != nullptr) {
			prevNode->setNext(newNode);
			currNode->setPrev(prevNode);
		}
		if (prevNode == nullptr) {
			firstNode = newNode;
		}

		prevNode = newNode;
		currNode = currNode->getNext();

		if (currNode == nullptr) {
			lastNode = prevNode;
		}
		
		s++;
	}
}

template <class Type>
Deque<Type>& Deque<Type>::operator=(const Deque& other) {
    if (this != &other) {
        while (!isEmpty()) {
			Node<Type>* tempNode = firstNode;
			if (s > 1) {
			firstNode = firstNode->getNext();
			firstNode->setPrev(nullptr);
			}
			delete tempNode;
			s--;
        }
	}
	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;

	Node<Type>* currNode = other.firstNode;
	Node<Type>* prevNode = nullptr;

	while (currNode != nullptr) {
		Node<Type>* newNode = new Node<Type>{currNode->getData()};


		if (prevNode != nullptr) {
			prevNode->setNext(newNode);
			currNode->setPrev(prevNode);
		}
		if (prevNode == nullptr) {
			firstNode = newNode;
		}

		prevNode = newNode;
		currNode = currNode->getNext();



		if (currNode == nullptr) {
			lastNode = prevNode;
		}
		
		s++;
	}

	return *this;
}

template <class Type>
bool Deque<Type>::isEmpty() {
	return s <= 0;
}

template <class Type>
int Deque<Type>::size() {
	return s;
}

template <class Type>
Type Deque<Type>::first() {
	return firstNode->getData();
}

template <class Type>
Type Deque<Type>::last() {
	return lastNode->getData();
}

template <class Type>
void Deque<Type>::insertFirst(Type o) {	
	if(isEmpty()) 
	{
		firstNode = new Node<Type>(o);
	} else 
	{
		Node<Type>* newNode = new Node<Type>(o);
		newNode->setNext(firstNode);
		firstNode->setPrev(newNode);
		firstNode = newNode;
		if (lastNode == nullptr) {
			lastNode = newNode->getNext();
		}
	}
	s++;
}

template <class Type>
void Deque<Type>::insertLast(Type o) {
	if(isEmpty()) 
	{
		firstNode = new Node<Type>(o);
	} else if (s == 1) {
		lastNode = new Node<Type>(o);
		lastNode->setPrev(firstNode);
		firstNode->setNext(lastNode);
	} else 
	{
		
		Node<Type>* newNode = new Node<Type>(o);
		
		newNode->setPrev(lastNode);
		lastNode->setNext(newNode);
		lastNode = newNode;
		
	}
	s++;
}

template <class Type>
Type Deque<Type>::removeFirst() {
	if(isEmpty()){
		throw std::out_of_range("Stack empty");
	}
	Type elem = firstNode->getData();
	Node<Type>* tempNode = firstNode;
	firstNode = tempNode->getNext();
	if (firstNode != nullptr) {
	firstNode->setPrev(nullptr); 
	}
	delete tempNode;
	s--;
	return elem;
}

template <class Type>
Type Deque<Type>::removeLast() {
	if(isEmpty())
	{
		throw std::out_of_range("Stack empty");
	} else if (s < 1) 
	{
		throw std::out_of_range("Only 1 element");
	}
	Type elem = lastNode->getData();
	Node<Type>* tempNode = lastNode;
	lastNode = tempNode->getPrev();
	if (lastNode != nullptr) {
	lastNode->setNext(nullptr); 
	}
	delete tempNode;
	s--;
	return elem;
}

#endif
