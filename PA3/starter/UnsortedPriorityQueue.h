#ifndef UNSORTED_PRIORITY_QUEUE_H
#define UNSORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class UnsortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        UnsortedPriorityQueue();

        ~UnsortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
UnsortedPriorityQueue<Type>::UnsortedPriorityQueue() {
    capacity = 10;
    size = 0;
    arr = new Type[capacity];    
}

template <typename Type>
UnsortedPriorityQueue<Type>::~UnsortedPriorityQueue(){
    delete[] arr;
}

template <typename Type>
void UnsortedPriorityQueue<Type>::pq_insert(Type value) {
    if(size == capacity) {
        capacity *= 2;
        Type* temp_arr = new Type[capacity];
        for(int i = 0; i < size ; i++ ) {
            temp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = temp_arr;
    }
    arr[size] = value;
    size++;    
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_delete(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    
    Type min = arr[0];
    int minIndex = 0;
    for (int i = 0; i < size; i++) {
        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }
    for (int i = minIndex; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return min;
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_get_min(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    Type min = arr[0];
    for(int i = 0; i < size; i++){
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename Type>
int UnsortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif