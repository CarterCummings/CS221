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
    maxLoadFactor = 1.25; // This is a made up number!! refine? i hath refined. .9 to 1.25 seems best
    table.resize(capacity);
}

// destructor
ChainingHashTable::~ChainingHashTable() {}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
    if (load_factor() > maxLoadFactor) {
        resizeAndRehash();
    }

    if(!contains(key)) {
        num_elements++;
        table[hash(key)].emplace_front(key,val);
    }
    int index = hash(key);
    for(list<AbstractHashTable::HashEntry>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
        if(it->key == key) {
            table[index].erase(it);
            table[index].emplace_front(key,val);
            break; 
        }
    }
    
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	if (!contains(key)) {
        throw std::out_of_range("key not found remove");
    }
    int index = hash(key);
    int ret;
    for(list<AbstractHashTable::HashEntry>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
        if(it->key == key) {
            ret = it->val;
            table[index].erase(it);
            num_elements--; 
            break; 
        }
    }
    return ret;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) const {
	if (!contains(key)) {
        throw std::out_of_range("key not found get");
    }
    int index = hash(key);
    for(const auto& elm : table[index]) {
        if(elm.key == key) {
            return elm.val;
            
        }
    }
    throw std::out_of_range("Uh oh");

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