#include <bits/stdc++.h>

using namespace std;

void print(vector <string> perm) {
    for (string i: perm) {
        cout << i << " ";
    }
    cout << endl;
}

void formWord(string s, unordered_set <string> dictionary, vector <string> partial) {
    if (s.length() == 0) {
        print(partial);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        string word = s.substr(0, i + 1);
        if (dictionary.find(word) != dictionary.end()) {
            partial.push_back(word);
            formWord(s.substr(i + 1, s.length()), dictionary, partial);
            partial.pop_back();
        }
    }
}

void formWord(string s, string w, int i, unordered_set <string> dictionary, unordered_set <string> &words) {
    if (dictionary.find(w) != dictionary.end()) {
        words.insert(w);
    }
    if (i == s.length()) {
        return;
    }
    w = w + s[i];
    formWord(s, w, i + 1, dictionary, words);
    w = w.substr(0, w.length() - 1);
    formWord(s, w, i + 1, dictionary, words);
}

void formWord(string s, unordered_set <string> dictionary) {
    unordered_set <string> words;
    vector <string> partial;
    formWord(s, dictionary, partial);
}

int main() {
    string s = "catsanddog";
    unordered_set <string> dictionary = {"cat", "cats", "and", "sand", "dog"};
    formWord(s, dictionary);
}