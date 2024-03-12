#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <iostream>

using namespace std;

template <typename Type, typename Compare = std::greater<Type>>
class PriorityQueueHeap {
private:
    Compare compare;
    Type *arr;
    int capacity;
    int size;

    void heapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    PriorityQueueHeap(const PriorityQueueHeap& other);

    PriorityQueueHeap(const Compare& comp);

    PriorityQueueHeap& operator=(const PriorityQueueHeap& other);

    ~PriorityQueueHeap();

    int pq_size();

    bool is_pq_empty();
    
    Type pq_top();

    void pq_insert(Type x);

    Type pq_delete();
};

// Your implementation here

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap() : compare() {
    capacity = 10;
    size = 0;
    arr = new Type[capacity];
  
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::~PriorityQueueHeap(){
    delete[] arr;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const Compare& _comp) {
    capacity = 10;
    size = 0;
    arr = new Type[capacity];
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const PriorityQueueHeap& other) {
    capacity = other.capacity;
    size = other.size;
    compare = other.compare;
    arr = new Type[capacity];
    for(int i = 0; i < size; i++) { 
        arr[i] = other.arr[i];
    }    
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>& PriorityQueueHeap<Type, Compare>::operator=(const PriorityQueueHeap& other) {
    if (this != &other) {
        delete[] arr;
        compare = other.compare;
        capacity = other.capacity;
        size = other.size;
        arr = new Type[capacity];
        for(int i = 0; i < size; i++) { 
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_size() {
    return size;
}

template <typename Type, typename Compare>
bool PriorityQueueHeap<Type, Compare>::is_pq_empty(){
    return size == 0;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_parent(int i){
    return (i - 1) / 2;
}

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_top(){
    if (is_pq_empty()) {
        throw std::out_of_range("its empty");
    }
    return arr[0];
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::pq_insert(Type x) {
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


template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::bubbleUp(int i){
    while (i > 0 && !(compare(arr[i], arr[pq_parent(i)]))) {
        std::swap(arr[i], arr[pq_parent(i)]);
        i = pq_parent(i);
    }    
}

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_delete(){
    if (is_pq_empty()) {
        throw std::out_of_range("its empty");
    }
    Type top = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapify(0);
    
    return top;
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::heapify(int i){
    int leftB = 2 * i + 1;
    int rightB = 2 * i + 2;
    int root = i;

    if (leftB < size && !(compare(arr[leftB], arr[root]))) {
        root = leftB;
    }

    if (rightB < size && !(compare(arr[rightB], arr[root]))) {
        root = rightB;
    }

    if (root != i) {
        std::swap(arr[i], arr[root]);
        heapify(root);
    }   
}


/* SOURCES
*  https://www.cs.cornell.edu/courses/cs2110/2016sp/L17-PriorityQueuesAndHeaps/cs2110PqueuesHeaps.pdf
*
*
*/

#endif