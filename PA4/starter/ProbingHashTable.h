#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "AbstractHashTable.h"
#include <vector>

// Linear probing hash table class
class ProbingHashTable : public AbstractHashTable {
    private:
    std::vector<HashEntry> table;
    void resizeAndRehash();
    
    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key) const; 
    bool contains(std::string key) const;
};

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor 
ProbingHashTable::ProbingHashTable(): AbstractHashTable() {
    capacity = 11;
    num_elements = 0;
    maxLoadFactor = .7; 
    table.resize(capacity);
}

// destructor
ProbingHashTable::~ProbingHashTable() {
   
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
    bool cont = contains(key);
    if (load_factor() > maxLoadFactor) {
        resizeAndRehash();
    }
    int index = hash(key);

    while(1){
        if (!cont && (!table[index].isFilled || table[index].DELETED)) {
            table[index].key = key;
            table[index].val = val;
            table[index].DELETED = false;
            table[index].isFilled = true;
            num_elements++;
            break;
        } else if (cont && table[index].key == key && !table[index].DELETED) {
            table[index].val = val;
            table[index].DELETED = false;
            table[index].isFilled = true;
            break;
        }


        index++;
        if(index >= capacity) {
            index = 0;
        }
    }
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int index = hash(key);
    int start = index;

    do {
        if(table[index].key == key && !table[index].DELETED) {
            table[index].DELETED = true;
            table[index].isFilled = false;
            table[index].val = -1;
            table[index].key = "";
            num_elements--;
            return table[index].val;

        } else if (!table[index].isFilled && !table[index].DELETED) {
            throw std::out_of_range("no key found");
        }
        index++;
        if(index >= capacity) {
            index = 0;
        } 
    } while (index != start);
    throw std::out_of_range("no key found rem");
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) const {
	int index = hash(key);
    int start = index;

    do {
        if(table[index].key == key && !table[index].DELETED) {
            return table[index].val;
        } else if (!table[index].isFilled && !table[index].DELETED) {
            throw std::out_of_range("no key found get");
        }
        index++;
        if (index >= capacity) {
            index = 0;
        } 
    } while (index != start);

    throw std::out_of_range("no key found get");
}

bool ProbingHashTable::contains(std::string key) const {
	int index = hash(key);
    int start = index;

    do {
        if(table[index].key == key && !table[index].DELETED) {
            return true;
        } else if (!table[index].isFilled && !table[index].DELETED) {
            return false;
        }
        
        index++;
        if (index >= capacity) {
            index = 0;
        } 
    } while (index != start);

    return false;
}

void ProbingHashTable::resizeAndRehash() {
    int cap = capacity;
    capacity *= 2;
    num_elements = 0;
    int index;

    std::vector<HashEntry> newTable(capacity);

    for(int i = 0; i < cap; i++) {
        if(table[i].isFilled && !table[i].DELETED) {
            index = hash(table[i].key);

            while(1){
                if (!newTable[index].isFilled) {
                    newTable[index].val = table[i].val;
                    newTable[index].key = table[i].key;
                    newTable[index].isFilled = true;
                    num_elements++;
                    break;
                } 
                index++;
                if(index >= capacity) {
                    index = 0;
                }
            }


        }
    }
    table = move(newTable);    
}

#endif