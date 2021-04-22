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
        bool searchRec(Node *, int);
        
        void traversePreOrder(Node *);
        void traverseInOrder(Node *);
        void traversePostOrder(Node *);
        
        void levelOrder(); 
        void levelOrderNonRec();
        void levelOrderQueue();
        void RevLevelOrderQueue();
        void ZigZagLevelOrder();

        int height(Node *);

        int min_binary(Node *);
        int min_bst(Node *);

        bool equal(Node *, Node *);
        bool validate(Node *, int, int);

        void nodesAtK(Node *, int);

        int size(Node *);
        int countLeaves(Node *);
        int maxNode(Node *);
        bool areSibling(Node *, int fst, int snd);
        list <int> getAncestors(Node * head, int value);
        void invert(Node *);
        bool UnivalTree();
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

void BinarySearchTree::insertBST(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node * curr = root;
    Node * last;

    while (curr != nullptr) {
        last = curr;
        if (value < curr->value) {
            curr = curr->leftChild;
        }
        else {
            curr = curr->rightChild;
        }
    }

    if (value > last->value) {
        last->rightChild = new Node(value);
    }
    else {
        last->leftChild = new Node(value);
    }
}

Node * insert(Node * curr, int value) {
    if (curr == nullptr) {
        return new Node(value);
    }

    if (value < curr->value) {
        return insert(curr->leftChild, value);
    }
    else {
        return insert(curr->rightChild, value);
    }
    return curr;
}

void BinarySearchTree::insertRec(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    insert(root, value);
}

bool BinarySearchTree::search(int value) {
    Node * curr = root;

    while (curr != nullptr) {
        if (value == curr->value) {
            return true;
        }
        else if (value < curr->value) {
            curr = curr->leftChild;
        }
        else {
            curr = curr->rightChild;
        }
    }
    return false;
}

bool BinarySearchTree::searchRec(Node * root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == value) {
        return true;
    }
    return searchRec(root->leftChild, value) || searchRec(root->rightChild, value);
}

void BinarySearchTree::traversePreOrder(Node * root) {
    if (root == nullptr) {
        return;
    }

    cout << root->value << endl;
    traversePreOrder(root->leftChild);
    traversePreOrder(root->rightChild);
}

void BinarySearchTree::traverseInOrder(Node * root) {
    if (root == nullptr) {
        return;
    }

    traverseInOrder(root->leftChild);
    cout << root->value << endl;
    traverseInOrder(root->rightChild);
}

void BinarySearchTree::traversePostOrder(Node * root) {
    if (root == nullptr) {
        return;
    }
        
    traversePostOrder(root->leftChild);
    traversePostOrder(root->rightChild);
    cout << root->value << endl;
}

int BinarySearchTree::height(Node * root) {
    if (root == nullptr) {
        return -1;
    }
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return 0;
    }
    return 1 + max(height(root->leftChild), height(root->rightChild));
}

int BinarySearchTree::min_bst(Node * root) {
    if (root == nullptr) {
        return -1;
    }

    Node * last;
    while (root != nullptr) {
        last = root;
        root = root->leftChild;
    }
    return last->value;
}

int BinarySearchTree::min_binary(Node * root) {
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return root->value;
    }

    int left = min_binary(root->leftChild);
    int right = min_binary(root->rightChild);

    return min(min(left, right), root->value);
}

void getNodes(Node *root, int k, vector <int> &nodesAtK) {
    if (root == nullptr) {
        return;
    }
    if (k == 0) {
        nodesAtK.push_back(root->value);
    }
    
    getNodes(root->leftChild, k-1, nodesAtK);
    getNodes(root->rightChild, k-1, nodesAtK);
}

void BinarySearchTree::nodesAtK(Node * root, int k) {
    vector <int> nodesAtK;
    getNodes(root, k, nodesAtK);
    
    for (auto i = nodesAtK.begin(); i != nodesAtK.end(); ++i) {
        cout << *i << " ";
    }
}

bool BinarySearchTree::equal(Node * firstRoot, Node * secondRoot) {
    if (firstRoot == nullptr && secondRoot == nullptr) {
        return true;   
    }

    if (firstRoot != nullptr && secondRoot != nullptr) {
        return firstRoot->value == secondRoot->value
                && equal(firstRoot->leftChild, secondRoot->leftChild)
                && equal(firstRoot->rightChild, secondRoot->rightChild);
    }

    return false;
}

bool BinarySearchTree::validate(Node * root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->value < min || root->value > max) {
        return false;
    }

    return validate(root->leftChild, min, root->value - 1) 
           && validate(root->rightChild, root->value + 1, max);
}

void findNodesAtLevels(Node * root, vector <int> &nodesAtLevel) {
    if (root == nullptr) {
        return;
    }
    
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return;
    }

    if (root->leftChild != nullptr) {
        // nodesAtLevel.push_back(root->leftChild->value);
        cout << root->leftChild->value << endl;
    }
    if (root->rightChild != nullptr) {
        // nodesAtLevel.push_back(root->rightChild->value);
        cout << root->rightChild->value << endl;
    }

    findNodesAtLevels(root->leftChild, nodesAtLevel);
    findNodesAtLevels(root->rightChild, nodesAtLevel);
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

void BinarySearchTree::levelOrderNonRec() {
    if (root == nullptr) {
        return;
    }

    queue <Node *> levelOrderedElements;
    levelOrderedElements.push(root);

    while (!levelOrderedElements.empty()) {

        Node * node = levelOrderedElements.front();
        cout << node->value << " ";
        levelOrderedElements.pop();

        if (node->leftChild != nullptr) {
            levelOrderedElements.push(node->leftChild);
        }
        if (node->rightChild != nullptr) {
            levelOrderedElements.push(node->rightChild);
        }
    }
}

void BinarySearchTree::levelOrderQueue() {
    vector <vector<int>> result;

    Node * node = root;
    queue <Node *> nodes;
    nodes.push(node);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        vector <int> eachLevel;

        for (int i = 0; i < levelSize; i++) {
            node = nodes.front();
            eachLevel.push_back(node->value);
            nodes.pop();

            if (node->leftChild != nullptr) {
                nodes.push(node->leftChild);
            }
            if (node->rightChild != nullptr) {
                nodes.push(node->rightChild);
            }
        }

        result.push_back(eachLevel);
    }

    for (auto level: result) {
        for (int j = 0; j < level.size(); j++) {
            cout << level[j] << " ";
        }
        cout << endl;
    }
}

void BinarySearchTree::RevLevelOrderQueue() {
    deque <vector<int>> result;

    Node * node = root;
    queue <Node *> nodes;
    nodes.push(node);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        vector <int> eachLevel;

        for (int i = 0; i < levelSize; i++) {
            node = nodes.front();
            eachLevel.push_back(node->value);
            nodes.pop();

            if (node->leftChild != nullptr) {
                nodes.push(node->leftChild);
            }
            if (node->rightChild != nullptr) {
                nodes.push(node->rightChild);
            }
        }

        result.push_front(eachLevel);
    }

    for (auto level: result) {
        for (int j = 0; j < level.size(); j++) {
            cout << level[j] << " ";
        }
        cout << endl;
    }
}

void BinarySearchTree::ZigZagLevelOrder() {
    vector <vector<int>> result;
    Node * node = root;

    queue <Node *> nodes;
    nodes.push(node);
    bool leftToRight = true;

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        vector <int> eachLevel(levelSize);

        for (int i = 0; i < levelSize; i++) {
            node = nodes.front();
            nodes.pop();

            if (leftToRight) {
                eachLevel[i] = node->value;
            }
            else {
                eachLevel[levelSize - 1 - i] = node->value;
            }

            if (node->leftChild != nullptr) {
                nodes.push(node->leftChild);
            }
            if (node->rightChild != nullptr) {
                nodes.push(node->rightChild);
            }
        }

        result.push_back(eachLevel);
        leftToRight = !leftToRight;
    }

    for (auto level: result) {
        for (int j = 0; j < level.size(); j++) {
            cout << level[j] << " ";
        }
        cout << endl;
    }
}

int BinarySearchTree::size(Node * root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->leftChild) + size(root->rightChild);
}

int BinarySearchTree::countLeaves(Node * root) {
    if (root == nullptr) {
        return 0;
    }
    
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return 1;
    }
    return countLeaves(root->leftChild) + countLeaves(root->rightChild);
}

int BinarySearchTree::maxNode(Node * root) {
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return root->value;
    }
    return maxNode(root->rightChild);
}

bool BinarySearchTree::areSibling(Node * root, int value1, int value2) {
    if (root == nullptr) {
        return false;
    }
    if (root->leftChild == nullptr || root->rightChild == nullptr) {
        return false;
    }
    if ( (root->leftChild->value == value1 && root->rightChild->value == value2) || (root->leftChild->value == value1 && root->rightChild->value == value2)) {
        return true;
    }
    return areSibling(root->leftChild, value1, value2) || areSibling(root->rightChild, value1, value2);
}

bool findAncestors(Node * root, int value, list <int> &ancestors) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == value) {
        return true;
    }
    if (findAncestors(root->leftChild, value, ancestors) || findAncestors(root->rightChild, value, ancestors)) {
        ancestors.push_front(root->value);
        return true;
    }
    return false;
}

list <int> BinarySearchTree::getAncestors(Node * root, int value) {
    list <int> ancestors;
    findAncestors(root, value, ancestors);
    return ancestors;
}

void BinarySearchTree::invert(Node * root) {
    if (root == nullptr) {
        return;
    }
    
    Node * temp = root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = temp;

    invert(root->leftChild);
    invert(root->rightChild);
}

void isUnival(Node * root, unordered_set<int> &elements) {
    if (root == nullptr) {
        return;
    }
    elements.insert(root->value);
    isUnival(root->leftChild, elements);
    isUnival(root->rightChild, elements);
}
bool BinarySearchTree::UnivalTree() {
    unordered_set <int> elements;
    isUnival(root, elements);
    return elements.size() == 1;
}



int main() { 
    BinarySearchTree bsT(7);
    bsT.insertBST(4);
    bsT.insertBST(9);
    bsT.insertBST(1);
    bsT.insertBST(6);
    bsT.insertBST(8);
    bsT.insertBST(10);

    bsT.ZigZagLevelOrder();

    // list <int> ancestors;
    // list <int>::iterator itr;
    // ancestors = bsT.getAncestors(bsT.getRoot(), 5);

    // for (itr = ancestors.begin(); itr != ancestors.end(); itr++) {
    //     cout << *itr << endl;
    // }
    
    // if (bsT.UnivalTree()) {
    //     cout << "TRUE";
    // }
    // else {
    //     cout << "FALSE";
    // }
 
    // cout << bsT.searchRec(bsT.getRoot(), 10);
    cout << endl;

  return 0;
}