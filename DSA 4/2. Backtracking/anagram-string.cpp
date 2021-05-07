#include <bits/stdc++.h>

using namespace std;

void getAnagrams(string str, string ana, unordered_set <char> used) {
    if (ana.size() == str.size()) {
        cout << ana << " ";
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (i > 0 && str[i] == str[i - 1]) {
            continue;
        }
        char c = str[i];
        if (used.find(c) == used.end()) {
            used.insert(c);
            ana  = ana + c;
            
            getAnagrams(str, ana, used);

            ana = ana.substr(0, ana.length() - 1);
            used.erase(c);
        }
    }
}

void getAnagrams(string str) {
    unordered_set <char> used;
    sort(str.begin(), str.end());
    getAnagrams(str, "", used);
    cout << endl;
}

int main() {
    // anagram : god, gdo, dog, dgo, odg, ogd
    string str = "god";
    getAnagrams(str);
    return 0;
}