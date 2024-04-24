#include <iostream>
#include <thread>
using namespace std;


void mergearr(int *arr, int start, int middle, int end) {
    int arrOne = middle - start + 1;
    int arrTwo = end - middle;

    int *startArr = new int[arrOne];
    int *endArr = new int[arrTwo];

    for (int i = 0; i < arrOne; i++) {
        startArr[i] = arr[start + i];
    }
    for (int j = 0; j < arrTwo; j++) {
        endArr[j] = arr[middle + 1 + j];
    }

    int IarrOne = 0; 
    int IarrTwo = 0;
    int ImergedArr = start;

    while (IarrOne < arrOne && IarrTwo < arrTwo) {
        if (startArr[IarrOne] <= endArr[IarrTwo]) {
            arr[ImergedArr] = startArr[IarrOne];
            IarrOne++;
        }
        else {
            arr[ImergedArr] = endArr[IarrTwo];
            IarrTwo++;
        }
        ImergedArr++;
    }

    while (IarrOne < arrOne) {
        arr[ImergedArr] = startArr[IarrOne];
        IarrOne++;
        ImergedArr++;
    }

    while (IarrTwo < arrTwo) {
        arr[ImergedArr] = endArr[IarrTwo];
        IarrTwo++;
        ImergedArr++;
    }
    delete[] startArr;
    delete[] endArr;
}

void mergeSort(int * arr, int start, int end, int level) {
    if (start >= end) { return; } // checking for end case / invalid case

    int middle = start + (end - start) / 2;

    if (level > 0) {
        thread first(mergeSort, arr, start, middle , level - 1);
        thread second(mergeSort, arr, middle + 1, end , level - 1);
        first.join();
        second.join();
        mergearr(arr, start, middle, end);
    } else {
        mergeSort(arr, start, middle,level - 1); // first half
        mergeSort(arr, middle + 1, end, level - 1); // second half
        mergearr(arr, start, middle, end);
    }


}