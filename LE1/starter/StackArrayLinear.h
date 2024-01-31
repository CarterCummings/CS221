#ifndef STACK_LINEAR_ARRAY_H
#define STACK_LINEAR_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayLinear : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayLinear();

    ~StackArrayLinear();

    StackArrayLinear(const StackArrayLinear& other);

    StackArrayLinear& operator=(const StackArrayLinear& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackArrayLinear<T>::StackArrayLinear(){
    // Setting 1 to the be starting stack size 
    data = new T[1];
    length = 1;
    topIndex = 0;
}

template <typename T>
StackArrayLinear<T>::~StackArrayLinear(){
    delete[] data;
}

template <typename T>
StackArrayLinear<T>::StackArrayLinear(const StackArrayLinear& other) {
    data = new T[length];
    for (int i = 0; i <= topIndex; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayLinear<T>& StackArrayLinear<T>::operator=(const StackArrayLinear& other) {
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
bool StackArrayLinear<T>::isEmpty(){
    return topIndex == -1;
}

template <typename T>
int StackArrayLinear<T>::size(){
    return topIndex + 1;
}

template <typename T>
T& StackArrayLinear<T>::top(){
    static int temp = -1;

    if (isEmpty()) { 
        throw std::out_of_range("its empty");
    }
    temp = data[topIndex];

    return temp;
}

template <typename T>
T StackArrayLinear<T>::pop(){
    if (isEmpty()) {
            throw std::out_of_range("its empty");
            return data[topIndex]; 
        }

    T element = data[topIndex--];

    return element;
}

template <typename T>
void StackArrayLinear<T>::push(const T& e){
    if (topIndex == length - 1) {
            // If the stack is full, double its capacity
            T* newData = new T[length + 10];

            // Copy existing elements to the new array
            for (int i = 0; i <= topIndex; ++i) {
                newData[i] = data[i];
            }

            // Update length and swap the arrays
            length = length + 10;
            delete[] data;
            data = newData;
        }

        data[++topIndex] = e;
}

#endif