#include <bits/stdc++.h>

using namespace std;

int lcs(string a, string b, int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (a[i] != b[j]) {
        return max(lcs(a, b, i - 1, j), lcs(a, b, i, j - 1));
    } else {
        return 1 + lcs(a, b, i - 1, j - 1);
    }
}

//lcs in substring of a ending at i and substring of b ending at j
int lcsTopDown(string a, string b, int i, int j, vector <vector<int>> dp) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    } 

    if (a[i] != b[j]) {
        dp[i][j] = max(lcsTopDown(a, b, i - 1, j, dp), lcsTopDown(a, b, i, j - 1, dp));
        return dp[i][j];
    } else {
        dp[i][j] = 1 + lcsTopDown(a, b, i - 1, j - 1, dp);
        return dp[i][j];
    }
}

// bottom up
int lcsBottomUp(string a, string b) {
    int m = a.length();
    int n = b.length();
    vector <vector<int>> dp(m + 1, vector<int>((n + 1), 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void longestCommSubseq(string a, string b) {
    cout << lcs(a, b, a.length() - 1, b.length() - 1) << endl;

    vector <vector<int>> dp(a.length(), vector<int>(b.length(), - 1));
    cout << lcsTopDown(a, b, a.length() - 1, b.length() - 1, dp) << endl;
    cout << lcsBottomUp(a, b);
}

int main() {
    string a = "abc";
    string b = "def";

    longestCommSubseq(a, b);
    
    cout << endl;
    return 0;
}