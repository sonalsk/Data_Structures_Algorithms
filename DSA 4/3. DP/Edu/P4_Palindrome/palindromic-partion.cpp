#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int getPart(string s, int i, int j) {
    if (i >= j || isPalindrome(s, i, j)) {
        return 0;
    }

    int minimumCuts = j - i;
    for (int k = i; k <= j; k++) {
        if (isPalindrome(s, k, i)) {
            minimumCuts = min(minimumCuts, 1 + getPart(s, k + 1, j));
        }
    }
    
    return minimumCuts;
}

bool isPalindrome(const string &st, int x, int y) {
    while (x < y) {
        if (st[x++] != st[y--]) {
            return false;
        }
    }
    return true;
}

int getPartition(string s) {
    int n = s.length();
    return getPart(s, 0, n - 1);
}

int main() {
    string s = "abdbca";
    int partition = getPartition(s);
    return 0;
}