#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main() {
    map <char, int> chars;
    map <char, int>::iterator itr;
    string s = "a green apple";

    for (char c: s) {
        if (c != ' ') {
            if (chars.count(c) == 0) {
                chars[c] = 1;
            }
            else {
                chars[c]++;
            }
        }
    }

    bool found = false;
    for (char c: s) {
        if (c != ' ') {
            if (chars.at(c) == 1) {
                cout << c << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "None" << endl;
    }
    return 0;
}