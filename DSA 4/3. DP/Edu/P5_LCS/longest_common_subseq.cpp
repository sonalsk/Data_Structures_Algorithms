#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int i, int j) {
    if (i == a.length() || j == b.length()) {
        return 0;
    }
    if (a[i] == b[j]) {
        return 1 + lcs(a, b, i + 1, j + 1);
    }
    return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}

int lcs(string a, string b, int i, int j, vector <vector <int>> dp) {
    if (i == a.length() || j == b.length()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        dp[i][j] = 1 + lcs(a, b, i + 1, j + 1, dp);
    } else {
        dp[i][j] = max(lcs(a, b, i + 1, j, dp), lcs(a, b, i, j + 1, dp));
    }

    return dp[i][j];
}

int lcs(string a, string b) {
    vector <vector <int>> dp(a.length() + 1, vector <int>(b.length() + 1, 0));

    for (int i = 1; i < a.length() + 1; i++) {
        for (int j = 1; j < b.length() + 1; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[a.length()][b.length()];
}

int lc_subseq(string a, string b) {
    vector <vector <int>> dp(a.length(), vector<int>(b.length(), -1));

    return lcs(a, b, 0, 0, dp);
}

int main() {
    string a = "abdca";
    string b = "cbda";

    int getLcs = lc_subseq(a, b);
    cout << getLcs << endl;

    return 0;
}