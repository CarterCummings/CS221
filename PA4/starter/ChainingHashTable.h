#ifndef CHAINING_H
#define CHAINING_H

#include "AbstractHashTable.h"
#include <vector>
#include <list>


// Chaining hash table class
class ChainingHashTable: public AbstractHashTable {
    private:
    std::vector<std::list<HashEntry>> table;
    void resizeAndRehash();

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, const int val); 
    int remove(std::string key); 
    int get(std::string key) const;
    bool contains(std::string key) const;
};


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor
ChainingHashTable::ChainingHashTable(): AbstractHashTable() {
    capacity = 11;
    num_elements = 0;
    maxLoadFactor = 3; // This is a made up number!! refine?
    table.resize(capacity);
}

// destructor
ChainingHashTable::~ChainingHashTable() {}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
    if (load_factor() > maxLoadFactor) {
        resizeAndRehash();
    }
    
    table[hash(key)].emplace_front(key,val);
    num_elements++;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	if (!contains(key)) {
        throw std::out_of_range("key not found remove");
    }
    int ret = table[hash(key)].front().val;
    table[hash(key)].pop_front();
    num_elements--;
    return ret;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) const {
	if (!contains(key)) {
        throw std::out_of_range("key not found get");
    }
    return table[hash(key)].front().val;
}

bool ChainingHashTable::contains(const std::string key) const {
	int index = hash(key);
    for(const auto& elm : table[index]) {
        if(elm.key == key) {
            return true;
        }
    }
    return false;
}

void ChainingHashTable::resizeAndRehash() {
    int cap = capacity;
    capacity *= 2;
    num_elements = 0;

    std::vector<std::list<HashEntry>> newTable(capacity);

    for (int i = 0; i < cap; i++) {
            for (const auto& elm : table[i]) {
                newTable[hash(elm.key)].push_back(elm);
                num_elements++;
            }
        }
    table = move(newTable);

}

#endif