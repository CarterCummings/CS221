#include <iostream>
#include <queue>
using namespace std;

void bubbleSort(int *arr, int size){
    bool moved;
    for (int i = 0; i < size - 1; i++) {
        moved = false;
        
        for (int j = 0; j < size - i - 1; j++) {    
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moved = true;
            }
        }

        if (!moved) {
            break;
        }
    }   
}

void heapify(int *arr, int size, int i) {
    int largest = i; // root
    int lft = 2 * i + 1; // left node
    int rgt = 2 * i + 2; // right node

    if (lft < size && arr[lft] > arr[largest]) {
        largest = lft;
    }

    if (rgt < size && arr[rgt] > arr[largest]) {
        largest = rgt;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int *arr, int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }    
}

void mergearr(int *arr, int start, int middle, int end) {

}

void mergeSort(int * arr, int start, int end) {
    if (start >= end) { return; }

    int middle = start + (end - start) / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
    mergearr(arr, start, middle, end);
}

int cut(int *arr, int start, int end) {
    
    int largest = arr[end];
    int i=(start-1);

    for(int j=start;j<=end;j++) {
        if(arr[j]<largest) {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[end]);
    return (i+1);
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int pivot = cut(arr, start, end);

        quickSort(arr,start,pivot - 1);
        quickSort(arr,pivot + 1,end);   

    }
}
