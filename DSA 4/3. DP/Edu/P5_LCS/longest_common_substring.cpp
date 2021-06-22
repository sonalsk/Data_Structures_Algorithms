#include <bits/stdc++.h>
using namespace std;

// recursion - O(3^(m + n))
int lcs(string a, string b, int i, int j, int count) {
    if (i == a.length() || j == b.length()) {
        return count;
    }

    if (a[i] == b[j]) {
        count = lcs(a, b, i + 1, j + 1, count + 1);
    }

    return max(count, max(lcs(a, b, i + 1, j, 0), lcs(a, b, i, j + 1, 0)));
}

// top down
int lcs(string a, string b, int i, int j, int count, vector <vector <int>> dp) {
    if (i == a.length() || j == b.length()) {
        return count;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        count = lcs(a, b, i + 1, j + 1, count + 1);
    }

    dp[i][j] = max(count, max(lcs(a, b, i + 1, j, 0), lcs(a, b, i, j + 1, 0)));
    return dp[i][j];
}

//bottom up - O(m * n)
int lcs(string a, string b) {
    vector <vector <int>> dp(a.length() + 1, vector <int> (b.length() + 1, 0));
    int maxLong = 0;

    for (int i = 1; i < a.length() + 1; i++) {
        for (int j = 1; j < b.length() + 1; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLong = max(maxLong, dp[i][j]);
            }
        }
    }

    return maxLong;
}

int lcs(string a, string b) {
    vector <int> dp(min(a.length(), b.length()) + 1);
    dp[0] = 0;
    int maxLong = 0;

    for (int i = 1; i < min(a.length(), b.length()); i++) {
        if (a[i] == b[i]) {
            dp[i] = 1 + dp[i - 1];
            maxLong = max(maxLong, dp[i]);
        } else {
            dp[i] = 0;
        }
    }

    return maxLong;
}

int lc_substring(string a, string b) {
    return lcs(a, b);
}

int main() {
    string a = "abdca";
    string b = "cbda";

    int get_lcs = lc_substring(a, b);
    cout << get_lcs << endl;

    return 0;
}