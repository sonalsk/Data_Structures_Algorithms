#include <bits/stdc++.h>

using namespace std;

string mergeRec(string a, string b, string c, int i, int j) {
    if (i == a.length()) {
        c += b.substr(j + 1);
        return c;
    }
    if (j == b.length()) {
        c += a.substr(i + 1);
        return c;
    }
    if (a[i] < b[j]) {
        c += a[i];
        return mergeRec(a, b, c, i + 1, j);
    } else {
        c += b[j];
        return mergeRec(a, b, c, i, j + 1);
    }
}

string merge(string a, string b) {
    return mergeRec(a, b, "", 0, 0);
}

string mergeSoln(string a, string b) {
    if (a.length() == 0) {
        if (b.length() > 0) {
            return b;
        }
        return a;
    }
    if (b.length() == 0) {
        return a;
    }
    if (a[0] < b[0]) {
        return a[0] + mergeSoln(a.substr(1), b);
    }
    else {
        return b[0] + mergeSoln(a, b.substr(1));
    }
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << mergeSoln(a, b) << endl;
    return 0;
}