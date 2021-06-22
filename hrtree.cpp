class Node {
    public:
        int value;
        Node * leftChild;
        Node * rightChild;
        Node();
        Node(int);
};

Node::Node(int val) {
    value = val;
    leftChild = NULL;
    rightChild = NULL;
}

class BinaryTree {
    private:
        Node * root;
    public:
        BinaryTree() {
            root = NULL;
        }
        Node * getRoot() {
            return root;
        }

        void insertBT(int);
        void invert(Node *, int);
        void traverseInOrder(Node *);
};

void BinaryTree::insertBT(int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
 
    queue <Node *> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->value == -1) {
            continue;
        }
 
        if (temp->leftChild != NULL) {
            q.push(temp->leftChild);
        }
        else {
            temp->leftChild = new Node(val);
            return;
        }
 
        if (temp->rightChild != NULL) {
            q.push(temp->rightChild);
        }
        else {
            temp->rightChild = new Node(val);
            return;
        }
    }
}

void invertR(Node * root, int q, int p) {
    if (root->value == -1) {
        return;
    }
    
    invertR(root->leftChild, q, p + 1);
    invertR(root->rightChild, q, p + 1);
    
    Node * temp = root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = temp;
}

void BinaryTree::invert(Node * root, int q) {
    invertR(root, q, 0);
}

void BinaryTree::traverseInOrder(Node * node) {
    if (node == NULL) {
        return;
    }
    traverseInOrder(node->leftChild);
    cout << node->value << " ";
    traverseInOrder(node->rightChild);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector <vector<int>> invertM;
    
    BinaryTree bt;
    bt.insertBT(1);
    
    int n = indexes.size();
    for (int i = 0; i < n; i++) {
        bt.insertBT(indexes[i][0]);
        bt.insertBT(indexes[i][1]);
    }
    
    bt.traverseInOrder(bt.getRoot());
    
    int qn = queries.size();
    for (int i = 0; i < qn; i++) {
        int q = queries[i];
        bt.invert(bt.getRoot(), q);
        
        cout << endl;
        bt.traverseInOrder(bt.getRoot());
    }
    
    
    return invertM;
}