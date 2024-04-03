#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "AbstractHashTable.h"
#include <vector>

// Double hashing hash table class
    class DoubleHashTable : public AbstractHashTable {
        private:
        // helper functions
        int secondHash(std::string s) const;
        std::vector<HashEntry> table;
        int prevPrime;
        void resizeAndRehash();

        public: 
        DoubleHashTable();
        ~DoubleHashTable(); 
        void insert(std::string key, int val); 
        int remove(std::string key); 
        int get(std::string key) const; 
        bool contains(std::string key) const;
    };


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor 
DoubleHashTable::DoubleHashTable(): AbstractHashTable() {
    capacity = 11;
    num_elements = 0;
    maxLoadFactor = .7; 
    table.resize(capacity);
    prevPrime = 7;
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
    if (load_factor() > maxLoadFactor) {
        resizeAndRehash();
    }
    bool cont = contains(key);
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


        index += secondHash(key);
        if(index >= capacity) {
            index = index % capacity;
        }
    }

    
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
	cout << "new insert" << endl;
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

        index += secondHash(key);
        if(index >= capacity) {
            index = index % capacity;
        }
    } while (index != start);
    throw std::out_of_range("no key found rem");
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) const {
	int index = hash(key);
    int start = index;

    do {
        if(table[index].key == key && !table[index].DELETED) {
            return table[index].val;
        } else if (!table[index].isFilled && !table[index].DELETED) {
            throw std::out_of_range("no key found get");
        }
        index += secondHash(key);
        if(index >= capacity) {
            index = index % capacity;
        }
    } while (index != start);

    throw std::out_of_range("no key found get");
}

bool DoubleHashTable::contains(std::string key) const {
	int index = hash(key);
    int start = index;

    do {
        if(table[index].key == key && !table[index].DELETED) {
            return true;
        } else if (!table[index].isFilled && !table[index].DELETED) {
            return false;
        }
        
        index += secondHash(key);
        if(index >= capacity) {
            index = index % capacity;
        }
    } while (index != start);

    return false;
}

void DoubleHashTable::resizeAndRehash() {
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
                index += secondHash(table[i].key);
                if(index >= capacity) {
                    index = index % capacity;
                }
            }


        }
    }
    table = move(newTable);    

    do {
        prevPrime = findNextPrime(prevPrime);
    } while (findNextPrime(prevPrime) < capacity);
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) const {
	unsigned long hash = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		hash = 37 * hash + (s[i] - '0');
	}
    //cout << "Prime: " << prevPrime << endl;
	return prevPrime - (hash % prevPrime);
}


#endif