#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template <typename Type>
class PriorityQueueHeap : public AbstractPriorityQueue<Type> {
private:
    Type *arr;
    int capacity;
    int size;
    
    void minHeapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    ~PriorityQueueHeap();

    int pq_size();
    
    Type pq_get_min();

    void pq_insert(Type value);

    Type pq_delete();
};

// Your implementation here

template <typename Type>
PriorityQueueHeap<Type>::PriorityQueueHeap(){
    capacity = 10;
    size = 0;
    arr = new Type[capacity];
}

template <typename Type>
PriorityQueueHeap<Type>::~PriorityQueueHeap(){
    delete[] arr;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_size() {
    return size;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_parent(int i){
    return (i - 1) / 2;
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_get_min(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    return arr[0];
}

template <typename Type>
void PriorityQueueHeap<Type>::pq_insert(Type x) {
    if(size == capacity) {
        capacity *= 2;
        Type* temp_arr = new Type[capacity];
        for(int i = 0; i < size ; i++ ) {
            temp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = temp_arr;
    }
    arr[size] = x;
    size++;
    bubbleUp(size - 1);    
}


template <typename Type>
void PriorityQueueHeap<Type>::bubbleUp(int i){
    while (i > 0 && (arr[i] < arr[pq_parent(i)]) ) {
        std::swap(arr[i], arr[pq_parent(i)]);
        i = pq_parent(i);
    }        
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_delete(){
    if (size == 0) {
        throw std::out_of_range("its empty");
    }
    Type top = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(0);
    
    return top;
}

template <typename Type>
void PriorityQueueHeap<Type>::minHeapify(int i){
    
    auto smallerchild = [&] (int j) {
        int root = j;
        int branch = 2 * j + 2;
        if (branch >= size || arr[branch] > arr[branch - 1]) {
            branch--;
        }
        return branch;
    };

    int c = smallerchild(i);
    while(c < size && (arr[i] > arr[c])) {
        std::swap(arr[i], arr[c]);
        i = c;
        c = smallerchild(i);
    }
}

#endif