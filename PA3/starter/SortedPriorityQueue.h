#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class SortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        SortedPriorityQueue();

        ~SortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
SortedPriorityQueue<Type>::SortedPriorityQueue() {
    capacity = 10;
    size = 0;
    arr = new Type[capacity];
}

template <typename Type>
SortedPriorityQueue<Type>::~SortedPriorityQueue(){
    delete[] arr;
}

template <typename Type>
void SortedPriorityQueue<Type>::pq_insert(Type value) {
    if(size == capacity) {
        capacity *= 2;
        Type* temp_arr = new Type[capacity];
        for(int i = 0; i < size ; i++ ) {
            temp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = temp_arr;
    }
    int i = 0;
    while(value > arr[i] && i < size){
        i++;
    }
    for(int j = size; j > i ; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = value;
    size++;   
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_delete(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    Type top = arr[0];
    for(int i = 0; i< size; i++ ) {
        arr[i] = arr[i+1];
    }
    size--;
    return top;
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_get_min(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    return arr[0];
}

template <typename Type>
int SortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif