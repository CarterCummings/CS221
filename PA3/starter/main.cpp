#include "AbstractPriorityQueue.h"
#include "PriorityQueueHeap.h"
#include "UnsortedPriorityQueue.h"
#include "SortedPriorityQueue.h"
#include <math.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

#ifndef TEST

int main() { 
    const int POWER = 5;
    SortedPriorityQueue<int> pq1;
    UnsortedPriorityQueue<int> pq2;
    PriorityQueueHeap<int> pq3;

    // Insert
    // INSERT PQ1 Test
    cout << "Insert" << endl;
    for(int i = 0; i <= POWER; i++) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq1.pq_insert(rand() % 200 + 1);
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Stored," << "10^" << i << "," << duration.count() << endl;

    }

    // INSERT PQ2 Test
    for(int i = 0; i <= POWER; i++) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq2.pq_insert(rand() % 200 + 1);
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Unsorted," << "10^" << i << "," << duration.count() << endl;
    }

    // INSERT PQ3 Test
    for(int i = 0; i <= POWER; i++) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq3.pq_insert(rand() % 200 + 1);
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Heap," << "10^" << i << "," << duration.count() << endl;
    }
    

    // Delete
    // Delete PQ1 Test
    cout << "Delete" << endl;
    for(int i = POWER; i >= 0; i--) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq1.pq_delete();
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Sorted," << "10^" << i << "," << duration.count() << endl;
    }

    // DELETE PQ2 Test
    for(int i = POWER; i >= 0; i--) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq2.pq_delete();
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Unsorted," << "10^" << i << "," << duration.count() << endl;
    }

    // DELETE PQ3 Test
    for(int i = POWER; i >= 0; i--) {
        auto start = high_resolution_clock::now();
        for(int j = 10; j < pow(10,i); j++) {
            pq3.pq_delete();
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Heap," << "10^" << i << "," << duration.count() << endl;
    }

    return 0;
}
#endif