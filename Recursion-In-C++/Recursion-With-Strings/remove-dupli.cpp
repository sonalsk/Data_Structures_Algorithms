#include <bits/stdc++.h>

using namespace std;

void removeDupliRec(string & s, int i) {
    if (i == s.length() - 1) {
        return;
    }
    if (s[i] == s[i + 1]) {
        s = s.substr(0, i) + s.substr(i + 1);
        removeDupliRec(s, i);
        return;
    }
    else {
        removeDupliRec(s, i + 1);
    }
}

void removeDuplicates(string & s) {
    removeDupliRec(s, 0);
}

int main() {
    string s;
    getline(cin, s);
    removeDuplicates(s);
    cout << s << endl;
    return 0;
}