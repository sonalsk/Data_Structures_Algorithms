#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int minDeletions(string s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }

    if (s[i] == s[j]) {
        return 2 + minDeletions(s, i + 1, j - 1);
    }

    return max(minDeletions(s, i + 1, j), minDeletions(s, i, j - 1));
}

int minDeletions(string s, int i, int j, vector <vector <int>> dp) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (dp[i][j] == -1) {
        return dp[i][j];
    }

    if (s[i] == s[j]) {
        dp[i][j] = 2 + minDeletions(s, i + 1, j - 1);
    } else {
        dp[i][j] = max(minDeletions(s, i + 1, j), minDeletions(s, i, j - 1));
    }

    return dp[i][j];
}

int minDeletions(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int> (n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}


int minDelete(string s) {
    int n = s.length();
    return (n - minDeletions(s));
}

int main() {
    string s = "abdbca";

    cout << minDelete("abdbca") << endl;
    cout << minDelete("cddpd") << endl;
    cout << minDelete("pqr") << endl;

    return 0;
}