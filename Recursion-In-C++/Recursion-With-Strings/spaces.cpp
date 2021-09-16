#include <bits/stdc++.h>

using namespace std;

void removeSpacesRec(string & s, int i) {
    if (i == s.length()) {
        return;
    }
    if (s[i] == ' ') {
        s = s.substr(0, i) + s.substr(i + 1);
        removeSpacesRec(s, i);
        return;
    }
    else {
        removeSpacesRec(s, i + 1);
    }
}

void removeSpaces(string & s) {
    removeSpacesRec(s, 0);
}

int main() {
    string s;
    getline(cin, s);
    removeSpaces(s);
    cout << s << endl;
    return 0;
}