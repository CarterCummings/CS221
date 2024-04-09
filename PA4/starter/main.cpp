#include "AbstractHashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

#include <chrono>
using namespace std::chrono;

#define POWER 6

void testInsert(AbstractHashTable* aht, vector<string> words, int power) {
    for (int i = 0; i < pow(10,power); i++) {
        std::string word = words[i];
        if (!aht->contains(word)) {
            aht->insert(word, 1);
        } else {
            int curVal = aht->get(word);
            aht->insert(word, curVal + 1);
        }
    }
}

int main() {
    std::string filename = "dictionary.txt";
    std::ifstream file(filename);
    std::srand(time(NULL));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }

    vector<string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }



    cout << "Chaining" << endl;
    for(int i = 0; i <= POWER; i++) {
        AbstractHashTable* cht = new ChainingHashTable();
        auto start = high_resolution_clock::now();
        testInsert(cht, words, i);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "10^" << i << "," << duration.count() << endl;

        delete cht;
    }
    

    
    
    
    cout << "Probing" << endl;
    for(int i = 0; i <= POWER; i++) {
        AbstractHashTable* pht = new ProbingHashTable();
        auto start = high_resolution_clock::now();
        testInsert(pht, words, i);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "10^" << i << "," << duration.count() << endl;

        delete pht;
    }    
    
    cout << "Double Hash" << endl;
    for(int i = 0; i <= POWER; i++) {
        AbstractHashTable* dht = new DoubleHashTable();
        auto start = high_resolution_clock::now();
        testInsert(dht, words, i);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "10^" << i << "," << duration.count() << endl;

        delete dht;
    }
}