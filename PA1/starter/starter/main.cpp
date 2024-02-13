#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"
#include "StackLinkedList.h"

#include <chrono>
using namespace std::chrono;


void testingFunc1(StackLinkedList<int>& x, int t) {
    auto start = high_resolution_clock::now();

    for(int i = 0; i < t ; i++) {
        x.push(rand() % 100 + 1);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by StackLL" << t << ": " << duration.count() << " microseconds" << endl;
}

void testingFunc2(StackArrayDouble<int>& x, int t) {
    auto start = high_resolution_clock::now();

    for(int i = 0; i < t ; i++) {
        x.push(rand() % 100 + 1);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by StackAD" << t << ": " << duration.count() << " microseconds" << endl;
}

void testingFunc3(StackArrayLinear<int>& x, int t) {
    auto start = high_resolution_clock::now();

    for(int i = 0; i < t ; i++) {
        x.push(rand() % 100 + 1);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by StackAL" << t << ": " << duration.count() << " microseconds" << endl;
}

int main() {
    StackLinkedList<int> stackLL10, stackLL1000, stackLL10000,stackLL100000;
    StackArrayDouble<int> stackAD10, stackAD1000, stackAD10000, stackAD100000;
    StackArrayLinear<int> stackAL10, stackAL1000, stackAL10000, stackAL100000;

    
    // Testing the dynamic stacks
    
 
    testingFunc1(stackLL10,10);
    testingFunc1(stackLL1000,1000);
    testingFunc1(stackLL10000,10000);
    testingFunc1(stackLL100000,100000);

    testingFunc2(stackAD10,10);
    testingFunc2(stackAD1000,1000);
    testingFunc2(stackAD10000,10000);
    testingFunc2(stackAD100000,100000);

    testingFunc3(stackAL10,10);
    testingFunc3(stackAL1000,1000);
    testingFunc3(stackAL10000,10000);
    testingFunc3(stackAL100000,100000);
 
    // Get ending timepoint

 
    

}