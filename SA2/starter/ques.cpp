#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

#ifndef ASCENDING_PATHS

int traverse(Node* node);

bool isLeaf(Node* node) {
    if(node->left == nullptr && node->right == nullptr) {
        return true;
    } else {
        return false;
    }
}

int traverse(Node* node) {
    int sum = 0;
    if(isLeaf(node)){
        return 1;
    }
    if(node->left != nullptr ) {
        if (node->left->data > node->data) {
            sum += traverse(node->left);
        }
    }

    if(node->right != nullptr ) {
        if (node->right->data > node->data) {
            sum += traverse(node->right);
        }
    }
    return sum;
}

int countAscendingPaths(Node* root){
    if(root == nullptr) {
        return 0;
    }
    if(isLeaf(root)) {
        return 0;
    }
    int sum = 0;
    if(root->left != nullptr ) {
        if (root->left->data > root->data) {
            sum += traverse(root->left);
        }
    }

    if(root->right != nullptr ) {
        if (root->right->data > root->data) {
            sum += traverse(root->right);
        }
    }

    
    
    
    return sum;
}

#endif

#ifndef LEFT_LEAVES
int traverseL(Node* node);
int traverseR(Node* node);

int traverseL(Node* node) {
    int sum = 0;
    if(isLeaf(node)){
        return node->data;
    }
    if(node->left != nullptr){
        sum += traverseL(node->left);
    }
    if(node->right != nullptr){
        sum += traverseR(node->right);
    }
    //std::cout << sum << endl;
    return sum;
}

int traverseR(Node* node) {
    int sum = 0;
    if(node->left != nullptr){
        sum += traverseL(node->left);
    }
    if(node->right != nullptr){
        sum += traverseR(node->right);
    }
    return sum;
}


int sumOfLeftLeaves(Node* root) { 
    int sum = 0;
    if (root == nullptr) {
        return 0;
    }
    if (isLeaf(root)) {
        return 0;
    } else {  
        if (root->left != nullptr) {
            sum += traverseL(root->left);
        }
        if (root->right != nullptr) {
            sum += traverseR(root->right);
        }

    }
    return sum;
}

#endif

#ifndef TEST_MODE
int main() {
    cout << "Sample Test case 1" << endl;
    {
        Node root(3);
        Node left(4), right(5);
        Node leftLeft(7), leftRight(8), rightLeft(9), rightRight(10);
        Node leftRightLeft(3), rightLeftRight(12);

        root.left = &left, root.right = &right;
        left.left = &leftLeft, left.right = &leftRight, right.left = &rightLeft, right.right = &rightRight;
        leftRight.left = &leftRightLeft, rightLeft.right = &rightLeftRight;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 10" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 3" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Sample Test case 2" << endl;
    {
        Node root(3);
        Node right(4);
        Node rightLeft(5), rightRight(16);
        Node rightRightLeft(14);

        
        root.right = &right;
        right.left = &rightLeft, right.right = &rightRight;
        rightRight.left = &rightRightLeft;

        
        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 19" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 1" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
}
#endif