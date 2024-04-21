#include "sort.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>

enum SORT_TYPE {
    BUBBLE_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT
};

void test(SORT_TYPE sort_type , int *arr , int n) {
    auto start = std::chrono::high_resolution_clock::now();
    if (sort_type == SORT_TYPE::BUBBLE_SORT) {
       bubbleSort(arr, n);
    } else if (sort_type == SORT_TYPE::HEAP_SORT) {
       heapSort(arr, n);
    } else if (sort_type == SORT_TYPE::MERGE_SORT) {
        mergeSort(arr, 0, n - 1);
    } else if (sort_type == SORT_TYPE::QUICK_SORT) {
        quickSort(arr, 0, n - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << n << "," << elapsed.count() << endl;
}

void reset(int *arr, vector<int> arrCopy) {
    for(int i = 0; i < 1000000; i++) {
        arr[i] = arrCopy[i];
    }
}

int main() {
    int n = 1000000;
    int *arr = new int[n];
    vector<int> arrCopy;

    for(int j=0; j<n; j++){
        arr[j] = rand() % 1000000 + 1;  // Random numbers between 1 and 10^6
        arrCopy.push_back(arr[j]);
    }


    cout << "Bubble: " << endl;
    for(int i = 10; i <= 1000000; i *= 10) {
        test(SORT_TYPE::BUBBLE_SORT, arr, i);
        reset(arr,arrCopy);
    }


    cout << endl << "Heap: " << endl;
    for(int i = 10; i <= 1000000; i *= 10) {
        test(SORT_TYPE::HEAP_SORT, arr, i);
        reset(arr,arrCopy);
    }

    cout << endl << "Merge: " << endl;
    for(int i = 10; i <= 1000000; i *= 10) {
        test(SORT_TYPE::MERGE_SORT, arr, i);
        reset(arr,arrCopy);
    }

    cout << endl << "Quick: " << endl;
    for(int i = 10; i <= 1000000; i *= 10) {
        test(SORT_TYPE::QUICK_SORT, arr, i);
        reset(arr,arrCopy);
    }


}