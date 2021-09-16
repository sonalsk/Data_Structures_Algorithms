#include <bits/stdc++.h>

using namespace std;

void removeDupItr(string s) {
    for (int i = 0; i < s.length(); i++) {
        bool foundDup = false;
        char c = s[i];

        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] == c) {
                foundDup = true;
                s = s.substr(0, j) + s.substr(j + 1, s.length());
            }
        }

        if (!foundDup) {
            cout << c;
        }
    }
    cout << endl;
}

void recRemove(string s, int curr, int check, bool found) {
    if (curr >= s.length()) {
        return;
    }
    if (check >= s.length()) {
        if (!found) {
            cout << s[curr];
        }
        found = false;
        recRemove(s, curr + 1, curr + 2, found);
        return;
    }
    if (s[check] == s[curr]) {
        found = true;
        s = s.substr(0, check) + s.substr(check + 1, s.length());
    }
     
    recRemove(s, curr, check + 1, found);
    return;
}

void removeRec(string s, int curr) {
    if (curr >= s.length()) {
        return;
    }

    bool found = false;
    for (int j = curr + 1; j < s.length(); j++) {
        if (s[j] == s[curr]) {
            found = true;
            s = s.substr(0, j) + s.substr(j + 1, s.length());
        }
    }

    if (!found) {
        cout << s[curr];
    }

    removeRec(s, curr + 1);
    return;
}

void removeDupRec(string s) {
    recRemove(s, 0, 1, false);
}

int main() {
    string s = "hello world";
    
    cout << "Iterative Self" << endl;
    removeDupItr(s);

    cout << "Recursive Self" << endl;
    removeDupRec(s);
    cout << endl;

    cout << "Recursive Soln" << endl;
    removeRec(s, 0);
    cout << endl;
    
    return 0;
}