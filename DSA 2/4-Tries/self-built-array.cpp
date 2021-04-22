#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        char val;
        Node * childern[26];
        bool isEndOfWord;
        
        Node(char value) {
            val = value;
        }

        string toString() {
            return "Value = " + val;
        }
};

class Trie {
    Node * root = new Node(' ');
    public:
        void insert(string);
        void display();
};

void Trie::insert(string word) {
    Node * curr = root;
    
    for (char c: word) {
        int index = c - 'a';
        if (curr->childern[index] == nullptr) {
            curr->childern[index] = new Node(c);
        }
        curr = curr->childern[index];
    }

    curr->isEndOfWord = true;
}



int main() {
    Trie * trie = new Trie();
    trie->insert("cat");
    trie->insert("can");
    cout << "Done" << endl;

    return 0;
}