#ifndef STACK_DOUBLE_ARRAY_H
#define STACK_DOUBLE_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayDouble : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayDouble();

    ~StackArrayDouble();

    StackArrayDouble(const StackArrayDouble& other);

    StackArrayDouble& operator=(const StackArrayDouble& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here

template <typename T>
StackArrayDouble<T>::StackArrayDouble(){
    // Setting 1 to the be starting stack size 
    data = new T[1];
    length = 1;
    topIndex = 0;
}

template <typename T>
StackArrayDouble<T>::~StackArrayDouble(){
    delete[] data;
}

template <typename T>
StackArrayDouble<T>::StackArrayDouble(const StackArrayDouble& other) {
    data = new T[length];
    for (int i = 0; i <= topIndex; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayDouble<T>& StackArrayDouble<T>::operator=(const StackArrayDouble& other) {
    if (this != &other) {
            delete[] data;

            length = other.length;
            topIndex = other.topIndex;

            data = new T[length];
            for (int i = 0; i <= topIndex; ++i) {
                data[i] = other.data[i];
            }
        }
    return *this;
}

template <typename T>
bool StackArrayDouble<T>::isEmpty(){
    return topIndex == -1;
}

template <typename T>
int StackArrayDouble<T>::size(){
    return topIndex + 1;
}

template <typename T>
T& StackArrayDouble<T>::top(){
    if (isEmpty()) { 
        throw std::out_of_range("its empty");
    }
    return data[topIndex];
}

template <typename T>
T StackArrayDouble<T>::pop(){
    if (isEmpty()) {
            throw std::out_of_range("its empty");
            return data[topIndex]; 
        }

    T element = data[topIndex--];

    return element;
}

template <typename T>
void StackArrayDouble<T>::push(const T& e){
    if (topIndex == length - 1) {
            // If the stack is full, double its capacity
            T* newData = new T[length*2];

            // Copy existing elements to the new array
            for (int i = 0; i <= topIndex; ++i) {
                newData[i] = data[i];
            }

            // Update length and swap the arrays
            length = length*2;
            delete[] data;
            data = newData;
        }

        data[++topIndex] = e;
}

#endif