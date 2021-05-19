#include <bits/stdc++.h>

using namespace std;

int minToRemoveCnt(string s, int f, int b) {
    if (f >= b) {
        return 0;
    }
    if (s[f] == s[b]) {
        return minToRemoveCnt(s, f + 1, b - 1);
    }
    else {
        int fR = minToRemoveCnt(s, f + 1, b);
        int bR = minToRemoveCnt(s, f, b - 1);
        return 1 + min(fR, bR);
    }
}

int minToRemoveCntTD(string s, int f, int b, vector <vector <int>> dp) {
    if (f >= b) {
        return 0;
    }
    if (dp[f][b] != -1) {
        return dp[f][b];
    }
    if (s[f] == s[b]) {
        dp[f][b] = minToRemoveCntTD(s, f + 1, b - 1, dp);
        return dp[f][b];
    }
    else {
        int fR = minToRemoveCntTD(s, f + 1, b, dp);
        int bR = minToRemoveCntTD(s, f, b - 1, dp);
        dp[f][b] = 1 + min(fR, bR);
        return dp[f][b];
    }
}

int minToRemoveBU(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector<int>(n, 0));

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[0][n - 1];
}

void minToRemove(string s) {
    int n = s.length();
    cout << minToRemoveCnt(s, 0, n - 1) << endl;

    vector <vector <int>> dp(n, vector<int>(n, -1));
    cout << minToRemoveCntTD(s, 0, n - 1, dp) << endl;
    cout << minToRemoveBU(s) << endl;
} 

int main() {
    string s = "kazayake";
    minToRemove(s);
    cout << endl;
    return 0;
}