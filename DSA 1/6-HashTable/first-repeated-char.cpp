#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main() {
    set <char> chars;
    set <char>::iterator itr;
    string s = "green apple";

    bool found = false;

    for (char c: s) {
        if (chars.find(c) != chars.end()) {
            cout << c << endl;
            found = true;
            break;
        }
        else {
            chars.insert(c);
        }
    }

    if (!found) {
        cout << "None" << endl;
    }

    return 0;
}