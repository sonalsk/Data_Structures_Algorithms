#include <bits/stdc++.h>
using namespace std;

// recursion - O(3^n)
int getSubs(string s, int i, int j) {
    if (i > j) {
        return 0;
    }

    if (i == j) {
        return 1;
    }
    
    int same = 0;
    if (s[i] == s[j]) {
        int remain = j - i - 1;
        if (remain == getSubs(s, i + 1, j - 1)) {
            same = remain + 2;
        }
    }

    int left = getSubs(s, i + 1, j);
    int right = getSubs(s, i, j - 1);

    return max(same, max(left, right));
}

// top down dp - O(n2)
int getSubs(string s, int i, int j, vector <vector <int>> dp) {
    if (i > j) {
        return 0;
    }

    if (i == j) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }    

    int same = 0;
    if (s[i] == s[j]) {
        int remain = j - i - 1;
        if (remain == getSubs(s, i + 1, j - 1, dp)) {
            same = remain + 2;
        }
    }

    int left = getSubs(s, i + 1, j, dp);
    int right = getSubs(s, i, j - 1, dp);

    dp[i][j] = max(same, max(left, right));
    return dp[i][j];
}

// bottom up - O(n2)
int getSubs(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            int same = 0;

            if (s[i] == s[j]) {
                int remain = j - i - 1;
                if (remain == dp[i + 1][j - 1]) {
                    same = remain + 2;
                }
            }

            int left = dp[i + 1][j];
            int right = dp[i][ j - 1];

            dp[i][j] = max(same, max(left, right));
        }
    }

    return dp[0][n - 1];
}

int findLPSLength(const string &st) {
    vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));

    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = true;
    }

    int maxLength = 1;

    for (int i = st.length() - 1; i >= 0; i--) {
        for (int j = i + 1; j < st.length(); j++) {
            
            if (st[i] == st[j]) {
                int remain = j - i - 1;
                
                if (remain == 0 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    maxLength = max(maxLength, remain + 2);
                }
            }
        }
    }

    return maxLength;
}

int longestPalindrome(string s) {
    vector <vector <int>> dp(s.length(), vector <int>(s.length(), -1));
    // return getSubs(s, 0, s.length() - 1, dp);
    return getSubs(s);
}

int main() {
    string s = "babad";
    cout << longestPalindrome("dabad") << endl;
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("abdbca") << endl;
    cout << longestPalindrome("cddpd") << endl;
    cout << longestPalindrome("pqr") << endl;
    return 0;
}