#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node * leftChild;
        Node * rightChild;
        Node();
        Node(int);
};

Node::Node() {
    value = 0;
    leftChild = NULL;
    rightChild = NULL;
}

Node::Node(int val) {
    value = val;
    leftChild = NULL;
    rightChild = NULL;
}

class BinarySearchTree {
    private:
        Node * root;
    public:
        BinarySearchTree();
        BinarySearchTree(int);
        Node * getRoot();
        void insertBST(int);
        void insertRec(int);
        bool search(int);
        void traversePreOrder(Node *);
        void traverseInOrder(Node *);
        void traversePostOrder(Node *);
        int height(Node *);
        int min_binary(Node *);
        int min_bst(Node *);
        bool equal(Node *, Node *);
        bool validate(Node *, int, int);
        void nodesAtK(Node *, int);
        void levelOrder(); 
};

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::BinarySearchTree(int rootValue) {
    root = new Node(rootValue);
}

Node * BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::insertBST(int val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }

    Node * currNode = root;
    Node * parent;

    while (currNode != nullptr) {
        parent = currNode;
        if (val < currNode->value) {
            currNode = currNode->leftChild;
        }
        else {
            currNode = currNode->rightChild;
        }
    }

    Node * node = new Node(val);
    if (val < parent->value) {
        parent->leftChild = node;
    }
    else{
        parent->rightChild = node;
    }
}

Node * insert(Node * currNode, int val) {
    if (currNode == nullptr) {
        return new Node(val);
    }
    else if (val < currNode->value) {
        currNode->leftChild = insert(currNode->leftChild, val);
    }
    else {
        currNode->rightChild = insert(currNode->rightChild, val);
    }
    return currNode;
}

void BinarySearchTree::insertRec(int val) {
    if (getRoot() == nullptr) {
        root = new Node(val);
        return;
    }
    insert(this->getRoot(), val);
}

bool BinarySearchTree::search(int val) {
    Node * currNode = getRoot();

    while (currNode != nullptr) {
        if (currNode->value == val) {
            return true;
        }
        else if (val < currNode->value) {
            currNode = currNode->leftChild;
        }
        else {
            currNode = currNode->rightChild;
        }
    }
    return false;
}

void BinarySearchTree::traversePreOrder(Node * node) {
    if (node == NULL) {
        return;
    }
    cout << node->value << " ";
    traversePreOrder(node->leftChild);
    traversePreOrder(node->rightChild);
}

void BinarySearchTree::traverseInOrder(Node * node) {
    if (node == NULL) {
        return;
    }
    traverseInOrder(node->leftChild);
    cout << node->value << " ";
    traverseInOrder(node->rightChild);
}

void BinarySearchTree::traversePostOrder(Node * node) {
    if (node == NULL) {
        return;
    }
    traversePostOrder(node->leftChild);
    traversePostOrder(node->rightChild);
    cout << node->value << " ";
}

int BinarySearchTree::height(Node * node) {
    if (node == NULL) {
        return -1;
    }
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return 0;
    }
    return 1 + max(height(node->leftChild), height(node->rightChild));
}

int BinarySearchTree::min_binary(Node * node) {
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return node->value;
    }
    int left = min_binary(node->leftChild);
    int right = min_binary(node->rightChild);

    return min(min(left, right), node->value);
}

int BinarySearchTree::min_bst(Node * node) {
    if (node == NULL) {
        return -1;
    }
    Node * current = node;
    Node * last = current;

    while (current != NULL) {
        last = current;
        current = current->leftChild;
    }
    return last->value;
}

bool BinarySearchTree::equal(Node * first, Node * second) {
    if (first == NULL && second == NULL) {
        return true;
    }

    if (first != NULL && second != NULL) {
        return first->value == second->value 
                && equal(first->leftChild, second->leftChild) 
                && equal(first->rightChild, second->rightChild);
    }

    return false;
}

bool BinarySearchTree::validate(Node * node, int minn, int maxx) {
    if (node == nullptr) {
        return true;
    }

    if (node->value < minn || node->value > maxx) {
        return false;
    }
    
    return validate(node->leftChild, minn, node->value - 1) &&
           validate(node->rightChild, node->value + 1, maxx);
}

void getNodes(Node * node, int k, vector<int> &nodes) {
    if (node == nullptr) {
        return;
    }
    if (k == 0) {
        nodes.push_back(node->value);
        return;
    }
    getNodes(node->leftChild, k - 1, nodes);
    getNodes(node->rightChild, k - 1, nodes);
}

void BinarySearchTree::nodesAtK(Node * node, int k) {
    vector <int> nodes;
    getNodes(node, k, nodes);
    
    for (auto i = nodes.begin(); i != nodes.end(); ++i) {
        cout << *i << " ";
    }
}

void BinarySearchTree::levelOrder() {
    for (int i = 0; i <= height(root); i++) {
        vector <int> values;
        getNodes(root, i, values);
        for (auto j = values.begin(); j != values.end(); ++j) {
            cout << *j << " ";
        }   
    }
}

int main() { 
    BinarySearchTree bsT(7);
    bsT.insertBST(4);
    bsT.insertBST(9);
    bsT.insertBST(1);
    bsT.insertBST(6);
    bsT.insertBST(8);
    bsT.insertBST(10);
 
    bsT.levelOrder();
    cout << endl;

  return 0;
}