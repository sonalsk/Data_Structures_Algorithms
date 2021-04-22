#include <bits/stdc++.h>

using namespace std;

class AVLNode {
    public:
        int height;
        int value;
        AVLNode * leftChild;
        AVLNode * rightChild;
        AVLNode(int val) {
            value = val;
        }
        string toString() {
            return "Value = " + to_string(value);
        }
};

class AVLTree {
    private:
        AVLNode * root;
    public:
        void insert(int); 
};

int heightNode(AVLNode * root) {
    if (root == nullptr) {
        return -1;
    }
    return root->height;
}

int balanceFactor(AVLNode * root) {
    return (root == nullptr) ? 0 : heightNode(root->leftChild) - heightNode(root->rightChild);
}

bool isLeftHeavy(AVLNode * node) {
    return balanceFactor(node) > 1;
}

bool isRightHeavy(AVLNode * node) {
    return balanceFactor(node) < -1;
}

void setHeight(AVLNode * root) {
    root->height = max(heightNode(root->leftChild), heightNode(root->rightChild)) + 1;
}

AVLNode * rotateLeft(AVLNode * root) {
    AVLNode * newRoot = root->rightChild;
    root->rightChild = newRoot->leftChild;
    newRoot->leftChild = root;
    setHeight(root);
    setHeight(newRoot);
    return newRoot;
}

AVLNode * rotateRight(AVLNode * root) {
    AVLNode * newRoot = root->leftChild;
    root->leftChild = newRoot->rightChild;
    newRoot->rightChild = root;
    setHeight(root);
    setHeight(newRoot);
    return newRoot;
}

AVLNode * balance(AVLNode * root) {
    if (isLeftHeavy(root)) {
        if (balanceFactor(root->leftChild) < 0) {
            root->leftChild = rotateLeft(root->leftChild);
        }
        return rotateRight(root);
    }

    else if (isRightHeavy(root)) {
        if (balanceFactor(root->rightChild) > 0) {
            root->rightChild = rotateRight(root->rightChild);
        }
        return rotateLeft(root);
    }
    return root;
}

AVLNode * insertRec(AVLNode * root, int val) {
    if (root == nullptr) {
        return new AVLNode(val);
    }
    if (val < root->value) {
        root->leftChild = insertRec(root->leftChild, val);
    }
    else {
        root->rightChild = insertRec(root->rightChild, val);
    }
    setHeight(root);
    return balance(root);
}

void AVLTree::insert(int val) {
    root = insertRec(root, val);
}

int main() {
    AVLTree * nt = new AVLTree();

    nt->insert(10);
    nt->insert(30);
    nt->insert(20);

    return 0;
}