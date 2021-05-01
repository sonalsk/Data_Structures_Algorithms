#include <bits/stdc++.h>

using namespace std;

bool isPalin(string s, int i) {
    if (i >= s.length() / 2) {
        return true;
    }
    if (s[i] != s[s.length() - 1 - i]) {
        return false;
    }
    return isPalin(s, i + 1);
}

bool isPalindrome(string s, int i, int j) {
    if (i >= j) {
        return true;
    }
    return s[i] == s[j] && isPalindrome(s, i + 1, j - 1);
}

bool isPalindrome(string s) {
    if (s.length() == 0) {
        return true;
    }
    return isPalindrome(s, 0, s.length() - 1);
}

int main() {
    string s = "ffg";
    if (isPalindrome(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}