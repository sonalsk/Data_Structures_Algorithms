#include <bits/stdc++.h>

using namespace std;

bool isPalinRec(vector <int> v, int i, int j) {
    if (i >= j) {
        return true;
    }
    if (v[i] != v[j]) {
        return false;
    }
    else {
        return isPalinRec(v, i + 1, j - 1);
    }
}

bool isPalindrome(vector <int> v) {
    return isPalinRec(v, 0, v.size() - 1);
}

int main() {
    vector <int> v = {1, 2, 3, 4, 2, 1};

    if (isPalindrome(v)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}