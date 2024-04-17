#include <iostream>
#include "SortedPriorityQueue.h"

using namespace std;

void radixSort(int *arr, int n) {

}


void insertionSort(int *arr, int n) {
    if(n == 0) {throw std::out_of_range("its empty");} 
    int temparr[n];
    int length = 0;
    bool found;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            temparr[0] = arr[i];
        } else {
            found = false;

            for (int j = 0; j < length; j++) {
                if (temparr[j] > arr[i]) {
                    // shift
                    for(int k = length; k >= j; k--) {
                        temparr[k] = temparr[k - 1];
                        
                    }
                    temparr[j] = arr[i];
                    // insert
                    found = true;
                    break;
                }
            }
            if(!found) {
                temparr[length] = arr[i];
            }

        }
        length++;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temparr[i];
    }
    
}
