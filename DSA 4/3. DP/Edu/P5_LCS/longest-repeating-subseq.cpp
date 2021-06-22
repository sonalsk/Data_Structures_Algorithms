#include <bits/stdc++.h>
using namespace std;

// Given a sequence, find the length of its longest repeating subsequence (LRS).
// A repeating subsequence will be the one that appears at least twice in the
// original sequence and is not overlapping (i.e. none of the 
// corresponding characters in the repeating subsequences have the same index).

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int lrs(string s, int i, int j) {
    if (i >= s.length() || j >= s.length()) {
        return 0;
    }

    if (s[i] == s[j] && i != j) {
        return 1 + lrs(s, i + 1, j + 1);
    }

    int left = lrs(s, i + 1, j);
    int right = lrs(s, i, j + 1);

    return max(left, right);
}

int lrs(string s, int i, int j, vector <vector <int>> dp) {
    if (i >= s.length() || j >= s.length()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s[i] == s[j] && i != j) {
        dp[i][j] = 1 + lrs(s, i + 1, j + 1, dp);
    } else{
        int left = lrs(s, i + 1, j, dp);
        int right = lrs(s, i, j + 1, dp);
        dp[i][j] = max(left, right);
    }
    
    return dp[i][j];    
}

int lrs(string s) {
    vector <vector <int>> dp(s.length() + 1, vector <int> (s.length() + 1, 0));
    int maxEl = 0;

    for (int i = 1; i < s.length() + 1; i++) {
        for (int j = 1; j < s.length() + 1; j++) {
            
            if (i != j && s[i - 1] == s[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

            maxEl = max(maxEl, dp[i][j]);
        }
    }

    return maxEl;
}

int longestRepeat(string s) {
    vector <vector <int>> dp(s.length(), vector <int>(s.length(), -1));
    return lrs(s);
}

int main() {
    cout << longestRepeat("tomorrow") << endl;
    cout << longestRepeat("aabdbcec") << endl;
    cout << longestRepeat("fmff") << endl;
    return 0;
}