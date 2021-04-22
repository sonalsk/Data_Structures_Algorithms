#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int val;
        Node * leftChild;
        Node * rightChild;
        Node() {
            val = 0;
            leftChild = nullptr;
            rightChild = nullptr;
        }

        Node (int v) {
            val = v;
            leftChild = nullptr;
            rightChild = nullptr;
        }
};

class BST {
    Node * root;
    public:
        BST();
        void display();
        Node * getRoot();
        void preOrder(Node *);
        void inOrder(Node *);
        void inOrderStack(Node *);
        void postOrder(Node *);
        void levelOrder(Node *);
        void insert(int);
        bool find(int);
        int depth(Node *);
        int height(Node *);
        int minBST();
        int minBin(Node *);
        bool equal(Node *, Node *);
        bool validate(Node *);
        void nodesAtK(Node *, int);
};

BST::BST() {
    root = nullptr;
}

Node * BST::getRoot() {
    return root;
}

void BST::preOrder(Node * root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void BST::inOrder(Node * root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->leftChild);
    cout << root->val << " ";
    inOrder(root->rightChild);
}

void BST::postOrder(Node * root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout << root->val << " ";
}

void BST::levelOrder(Node * root) {
    if (root == nullptr) {
        return;
    }
    queue <Node *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node * fst = nodes.front();
        cout << fst->val << " ";
        nodes.pop();

        if (fst->leftChild) {
            nodes.push(fst->leftChild);
        }
        if (fst->rightChild) {
            nodes.push(fst->rightChild);
        }
    }
}

void BST::display() {
    levelOrder(root);
    cout << endl;
}

void insertRec(int v, Node * root, Node * parent) {
    if (root == nullptr) {
        if (v < parent->val) {
            parent->leftChild = new Node(v);
        }
        else {
            parent->rightChild = new Node(v);
        }
        return;
    }
    if (v < root->val) {
        insertRec(v, root->leftChild, root);
        return;
    }
    return insertRec(v, root->rightChild, root);
}

void BST::insert(int v) {
    if (root == nullptr) {
        root = new Node(v);
        return;
    }
    insertRec(v, root, root);
    return;

    Node * curr = root;
    Node * parent = root;
    while (curr) {
        parent = curr;
        if (v < curr->val) {
            curr = curr->leftChild;
        }
        else {
            curr = curr->rightChild;
        }
    }

    if (v < parent->val) {
        parent->leftChild = new Node(v);
    }
    else {
        parent->rightChild = new Node(v);
    }
}

bool findRec(int v, Node * root) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == v) {
        return true;
    }
    return findRec(v, root->leftChild) || findRec(v, root->rightChild);
}

bool BST::find(int v) {
    return findRec(v, root);
    if (root == nullptr) {
        return false;
    }

    Node * curr = root;
    while (root) {
        if (v == root->val) {
            return true;
        }
        if (v < root->val) {
            root = root->leftChild;
        }
        else {
            root = root->rightChild;
        }
    }
    
    return false;
}

int BST::depth(Node * root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return 1;
    }
    return 1 + max(depth(root->leftChild), depth(root->rightChild));
}

int BST::height(Node * root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return 1;
    }
    return 1 + max(height(root->leftChild), height(root->rightChild));
}

int BST::minBin(Node * root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return root->val;
    }
    int a = minBin(root->leftChild);
    int b = minBin(root->rightChild);
    return min(min(a, b), root->val);
}

int minRecBST(Node * root) {
    if (root == nullptr) {
        return -1;
    }
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        return root->val;
    }
    return minRecBST(root->leftChild);
}

int BST::minBST() {
    if (root == nullptr) {
        return -1;
    }
    while (root->leftChild && root->rightChild) {
        root = root->leftChild;
    }
    return root->val;
}

bool BST::equal(Node * root1, Node * root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 != nullptr) {
        return false;
    }
    if (root2 == nullptr) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    bool left = equal(root1->leftChild, root2->leftChild);
    bool right = equal(root1->rightChild, root2->rightChild);
    return left && right;
}

// bool BST::equal(Node * root1, Node * root2) {
//     if (root1 == nullptr && root2 == nullptr) {
//         return true;
//     }
//     if (root1 != nullptr && root2 != nullptr) {
//         return root1->val == root2->val &&
//                equal(root1->leftChild, root2->leftChild) &&
//                equal(root1->rightChild, root2->rightChild);
//     }
//     return false;
// }

bool isValid(Node * root, Node * mini, Node * maxi) {
    if (root == nullptr) {
        return true;
    }
    
    if (mini && root->val <= mini->val || maxi && root->val >= maxi->val) {
        return false;
    }
    
    return isValid(root->leftChild, mini, root) && 
            isValid(root->rightChild, root, maxi);
}

bool validateRec(Node * root, int low, int high) {
    if (root == nullptr) {
        return true;
    }
    if (root->val < low || root->val > high) {
        return false;
    }
    return validateRec(root->leftChild, low, root->val - 1) && 
           validateRec(root->rightChild, root->val + 1, high);
}

bool BST::validate(Node * root) {
    return validateRec(root, INT_MIN, INT_MAX);
}

void BST::nodesAtK(Node * root, int k) {
    if (root == nullptr) {
        return;
    }
    if (k == 0) {
        cout << root->val << " ";
        return;
    }
    nodesAtK(root->leftChild, k - 1);
    nodesAtK(root->rightChild, k - 1);
}

void BST::inOrderStack(Node * root) {
    stack <Node *> ino;

    while (root != nullptr || ino.empty()) {
        while (root != nullptr) {
            ino.push(root);
            root = root->leftChild;
        }

        root = ino.top();
        ino.pop();
        cout << root->val << " ";
        root = root->rightChild;
    }
}

int main() {
    BST * tree = new BST();
    tree->insert(7);
    tree->insert(4);
    tree->insert(9);
    tree->insert(1);
    tree->insert(6);
    tree->insert(8); 
    tree->insert(10);   

    tree->display();

    tree->nodesAtK(tree->getRoot(), 1);
    cout << endl;
    return 0;
}