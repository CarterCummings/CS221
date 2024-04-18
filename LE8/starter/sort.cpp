#include <iostream>
#include "SortedPriorityQueue.h"

using namespace std;

void radixSort(int *arr, int n) {
    int maxNum = *max_element(arr, arr + n);
    for (int exp = 1; maxNum / exp > 0; exp *= 10){
        int temparr[n];
        int bucket[10] = {0};

        for (int i = 0; i < n; i++) {
            bucket[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            temparr[bucket[(arr[i] / exp) % 10] - 1] = arr[i];
            bucket[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {   
            arr[i] = temparr[i];
        }
    }
}


void insertionSort(int *arr, int n) {
    if(n == 0) {throw std::out_of_range("its empty");} 
    
    SortedPriorityQueue<int> pq;

    for(int i = 0; i < n; i++) {
        pq.pq_insert(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        arr[i] = pq.pq_delete();
    }
    
}
