#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Node {
public:
    int key;
    std::vector<Node*> forward;

    Node(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
private: 
    double P;
    int MAXLVL;
    Node* header;
    int level;

public:
    SkipList(int max_lvl, double p);
    ~SkipList();
    int randomLevel();
    void insertElement(int key);
    void deleteElement(int search_key);
    bool searchElement(int key);
    void displayList();
};


SkipList::SkipList(int max_lvl, double p) : MAXLVL(max_lvl), P(p), level(0) {
    header = new Node(-1, MAXLVL);
}

SkipList::~SkipList() {
    delete header;
} 

int SkipList::randomLevel() {
    int lvl = 0;
    while ((double)rand() / RAND_MAX < P && lvl < MAXLVL) {
        lvl++;
    }    
    
    return lvl;
}

void SkipList::insertElement(int key) {
        Node* update[MAXLVL + 1];
        Node* currNode = header;

        // Find the appropriate position to insert
        for (int i = level; i >= 0; i--) {
            while (currNode->forward[i] != nullptr && currNode->forward[i]->key < key) {
                currNode = currNode->forward[i];
            }
            update[i] = currNode;
        }

        currNode = currNode->forward[0];

        // If key is not present, insert it
        if (currNode == nullptr || currNode->key != key) {
            int newLevel = randomLevel();

            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++) {
                    update[i] = header;
                }
                level = newLevel;
            }

            Node* newNode = new Node(key, newLevel);

            for (int i = 0; i <= newLevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }

}

void SkipList::deleteElement(int search_key) {
        Node* update[MAXLVL + 1];
        Node* currNode = header;

        for (int i = level; i >= 0; i--) {
            while (currNode->forward[i] != nullptr && currNode->forward[i]->key < search_key) {
                currNode = currNode->forward[i];
            }
            update[i] = currNode;
        }

        currNode = currNode->forward[0];

        if (currNode != nullptr && currNode->key == search_key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != currNode)
                    break;
                update[i]->forward[i] = currNode->forward[i];
            }

            delete currNode;

            // Update the level of the list
            while (level > 0 && header->forward[level] == nullptr) {
                level--;
            }
        } 
}

bool SkipList::searchElement(int key) {
    Node* currNode = header;

    for (int i = level; i >= 0; i--) {
        while (currNode->forward[i] != nullptr && currNode->forward[i]->key < key) {
            currNode = currNode->forward[i];
        }
    }

    currNode = currNode->forward[0];

    return currNode != nullptr && currNode->key == key;
}

void SkipList::displayList() {
    std::cout << "\n*****Skip List******" << std::endl;
    Node* head = header;
    for (int lvl = 0; lvl <= level; lvl++) {
        std::cout << "Level " << lvl << ": ";
        Node* node = head->forward[lvl];
        while (node != nullptr) {
            std::cout << node->key << " ";
            node = node->forward[lvl];
        }
        std::cout << std::endl;
    }
}

#endif