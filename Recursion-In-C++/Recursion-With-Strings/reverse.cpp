#include <bits/stdc++.h>

using namespace std;

void reverseStrRec(string &s, int i) {
    if (i >= s.length() / 2) {
        return;
    }
    
    char c = s[i];
    s[i] = s[s.length() - 1 - i];
    s[s.length() - 1 - i] = c;

    reverseStrRec(s, i + 1);
}

void reverseStr(string & s) {
    reverseStrRec(s, 0);
}

int main() {
    string s;
    getline(cin, s);
    reverseStr(s);

    cout << s << endl;
    return 0;
}