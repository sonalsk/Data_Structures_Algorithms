#include <bits/stdc++.h>

using namespace std;

int isPalindrome(string text, int front, int back) {  
    if (front >= back) {
        return true;
    }
    if (text[front] != text[back]) {
        return false;
    }
    return isPalindrome(text, front + 1, back - 1);
}

int main() {
    string s;
    getline(cin, s);
    if (isPalindrome(s, 0, s.length() - 1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}