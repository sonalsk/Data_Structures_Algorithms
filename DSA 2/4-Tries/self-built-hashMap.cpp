#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        char val;
        map <char, Node *> childern;
        bool isEndOfWord;
        
        Node(char value) {
            val = value;
        }

        string toString() {
            return "Value = " + val;
        }

        bool hasChild(char ch) {
            return childern.find(ch) != childern.end();
        }

        void addChild(char ch) {
            childern[ch] = new Node(ch);
        }

        Node * getChild(char ch) {
            return childern[ch];
        }

        bool hasChildern() {
            return !childern.empty();
        }

        void removeChild(char ch) {
            childern.erase(ch);
        }
};

class Trie {
    Node * root = new Node(' ');
    public:
        void insert(string);
        bool contains(string);
        void PreOrderTraverse();
        void PostOrderTraverse();
        void remove(string);
        vector <string> findWords(string);
};

void Trie::insert(string word) {
    Node * curr = root;
    
    for (char c: word) {
        if (!curr->hasChild(c)) {
            curr->addChild(c);
        }
        curr = curr->getChild(c);
    }
    curr->isEndOfWord = true;
}

bool Trie::contains(string word) {
    if (word == "") {
        return false;
    }
    
    Node * curr = root;

    for (char c: word) {
        if (!curr->hasChild(c)) {
            return false;
        }
        curr = curr->getChild(c);
    }

    return curr->isEndOfWord;
}
 
void preTaverseRec(Node * root) {
    cout << root->val << endl;

    for (auto child: root->childern) {
        preTaverseRec(child.second);
    }
}
 
void postTaverseRec(Node * root) {
    for (auto child: root->childern) {
        postTaverseRec(child.second);
    }
    cout << root->val << endl;
}

void Trie::PreOrderTraverse() {
    preTaverseRec(root);
}

void removeRec(Node * root, string word, int index) {
    if (index == word.length()) {
        root->isEndOfWord = false;
        return;
    }

    char ch = word[index];
    Node * child = root->getChild(ch);

    if (child == nullptr) {
        return;
    }

    removeRec(child, word, index + 1);
    
    if (!child->hasChildern() && !child->isEndOfWord) {
        root->removeChild(ch);
    }
}

void Trie::remove(string word) {
    if (word == "") {
        return;
    }
    removeRec(root, word, 0);
}

Node * findLastNodeOf(string prefix, Node * root) {
    if (prefix == "") {
        return nullptr;
    }
    Node * curr = root;

    for (char ch: prefix) {
        Node * child = curr->getChild(ch);
        if (child == nullptr) {
            return nullptr;
        }
        curr = child;
    }
    return curr;
}

void findWordsRec(Node * root, string prefix, vector <string> &words) {
    if (root == nullptr) {
        return;
    }

    if (root->isEndOfWord) {
        words.push_back(prefix);
    }

    for (auto child: root->childern) {
        findWordsRec(child.second, prefix + child.first, words); 
    }
}

vector <string> Trie::findWords(string prefix) {
    Node * lastNode = findLastNodeOf(prefix, root);
    vector <string> words;
    findWordsRec(lastNode, prefix, words);

    for (string word: words) {
        cout << word << endl;
    }
    return words;
}

int main() {
    Trie * trie = new Trie();
    trie->insert("c");
    trie->insert("ca");
    trie->insert("car");
    trie->insert("carful");
    trie->insert("hello");

    trie->findWords("c");

    return 0;
}