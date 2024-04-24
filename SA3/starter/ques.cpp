#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "PriorityQueueHeap.h"

using namespace std;

#ifndef INTERSECTION_ARRAY
 
vector<int> intersectionOfTwoArrays(vector<int> nums, vector<int> otherNums) {
    unordered_map<int,int> umap;
    vector<int> intersection;

    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int key = nums[i];
        if (umap.find(key) == umap.end()) {
            umap.insert(make_pair(key,1));
        } else {
            umap[key] += 1;
        }

        
    
    }

    n = otherNums.size();
    for(int i = 0; i < n; i++) {
        int key = otherNums[i];
        if (umap.find(key) == umap.end()) {
            continue;
        } else {
            if (umap[key] > 0) {
                intersection.push_back(key);
            }
            umap[key] -= 1;

        }
    }


    return intersection;
}

#endif

#ifndef ROPE_GAME

int ropesGameCost(vector<int> ropes) {
    int total = 0;
    int n = ropes.size();
    PriorityQueueHeap pq;
    for(int i = 0; i < n; i++ ) {
        pq.pq_insert(ropes[i]);
    }

    int one = 0;
    int two = 0;
    while(pq.pq_size() >= 2) {
        one = pq.pq_delete();
        two = pq.pq_delete();
        total += (one + two);
        pq.pq_insert(one + two);
    }
    

    return total;
}

#endif

#ifndef TEST_MODE

int main() {
    // Test cases for intersectionOfTwoArrays:
    cout << "TEST CASES FOR intersectionOfTwoArrays" << endl;
    {
        cout << "Test Case 1:" << endl;
        vector<int> nums = {9, 8, 8, 7};
        vector<int> otherNums = {8, 8, 8, 9};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should contain two 8's and one 9" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 2:" << endl;
        vector<int> nums = {1, 8, 1, 8, 1, 7, 46, 1};
        vector<int> otherNums = {8, 1, 8, 1, 1, 203};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should contain two 8's and three 1's" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 3:" << endl;
        vector<int> nums = {1, 8, 7, 5, 53};
        vector<int> otherNums = {102, 203, 201, 103, 106, 107};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should be empty (should not see any numbers)" << endl;
        cout << endl;
    }

    cout << "TEST CASES FOR ropesGameCost" << endl;

    {
        cout << "Test Case 1: " << endl;
        vector<int> ropes = {3, 8, 4, 6, 7}; // 7 {6,7,7,8} 13 {7,8,13}
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 63;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
        cout << endl;
    }

     {
        cout << "Test Case 2: " << endl;
        vector<int> ropes = {3, 7, 9, 4};
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 44;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
    }

    return 0;
}
#endif