#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int minInsert(string s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    
    if (s[i] == s[j]) {
        return 2 + minInsert(s, i + 1, j - 1);
    }
    
    return max(minInsert(s, i + 1, j), minInsert(s, i, j - 1));
}

int minInsert(string s, int i, int j, vector <vector<int>> dp) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if (s[i] == s[j]) {
        dp[i][j] = 2 + minInsert(s, i + 1, j - 1, dp);
    } else {
        dp[i][j] = max(minInsert(s, i + 1, j, dp), 
                        minInsert(s, i, j - 1, dp));
    }
    
    return dp[i][j];
}

int minInsert(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int>(n));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int minInsertions(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int>(n, -1));
    return (n - minInsert(s));
}

int main() {
    string s = "abdbca";

    cout << minInsertions("abdbca") << endl;
    cout << minInsertions("cddpd") << endl;
    cout << minInsertions("pqr") << endl;

    return 0;
}