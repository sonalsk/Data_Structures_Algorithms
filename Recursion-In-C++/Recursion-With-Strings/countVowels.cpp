#include <bits/stdc++.h>

using namespace std;

int totalVowels(string text, int len, int index) { 
    unordered_set <char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    if (index == len) {
        return 0;
    }
    if (vowels.find(text[index]) != vowels.end()) {
        return 1 + totalVowels(text, len, index + 1);
    }
    else {
        return totalVowels(text, len, index + 1);
    }
} 

int main() {
    string s;
    getline(cin, s);
    cout << totalVowels(s, s.length(), 0) << endl;
    return 0;
}