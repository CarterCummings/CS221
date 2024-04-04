#include "AbstractHashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

int main() {

    AbstractHashTable* cht = new ChainingHashTable();

    delete cht;
    
    

    AbstractHashTable* pht = new ProbingHashTable();

    delete pht;


    AbstractHashTable* dht = new DoubleHashTable();
    
    
    delete dht;
}