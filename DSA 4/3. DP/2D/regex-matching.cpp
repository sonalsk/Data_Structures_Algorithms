#include <bits/stdc++.h>

using namespace std;

bool matchReg(string a, string b, int i, int j) {
    if ((i == -1 && j == -1) || (b.substr(0, j + 1) == "*")) {
        return true;
    }
    else if (i == -1 || j == -1) {
        return false;
    }
    if (a[i] == b[j]) {
        return matchReg(a, b, i - 1, j - 1);
    }
    else if (b[j] == '.') {
        return matchReg(a, b, i - 1, j - 1);
    }
    else if (b[j] == '*') {
        return matchReg(a, b, i - 1, j) || matchReg(a, b, i, j - 1);
    }
    return false;
}

int matchRegTD(string a, string b, int i, int j, vector <vector<int>> dp) {
    if ((i == -1 && j == -1) || (b.substr(0, j + 1) == "*")) {
        return 1;
    }
    else if (i == -1 || j == -1) {
        return 0;
    }
    if (dp[i][j] != 2) {
        return dp[i][j];
    }
    if (a[i] == b[j]) {
        dp[i][j] =  matchReg(a, b, i - 1, j - 1);
        return dp[i][j];
    }
    else if (b[j] == '.') {
        dp[i][j] =  matchReg(a, b, i - 1, j - 1);
        return dp[i][j];
    }
    else if (b[j] == '*') {
        dp[i][j] =  matchReg(a, b, i - 1, j) || matchReg(a, b, i, j - 1);
        return dp[i][j];
    }
    return 0;
}

int matchRegBU(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector <vector <bool>> dp(m, vector<bool>(n));
    dp[0][0] = true;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (b[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (b[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

void matchRegex(string a, string b) {
    matchRegBU(a, b);
}

int main() {
    string a = "greats";
    string b = "g*t*e";
    matchRegex(a, b);
}