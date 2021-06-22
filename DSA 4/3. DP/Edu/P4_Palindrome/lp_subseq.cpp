#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// basic solution bad
bool isPalindrome(string s) {
    string str = s;
    reverse(s.begin(), s.end());
    return s == str;
}
int getLongest(string s, int curr, string unpro) {
    if (curr == s.length()) {
        if (isPalindrome(unpro)) {
            return unpro.length();
        }
        return 0;
    }
    
    return max(getLongest(s, curr + 1, unpro + s[curr]),
                getLongest(s, curr + 1, unpro));
}

// recursive good - O(2^n)
int getLongest(string s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    
    if (s[i] == s[j]) {
        return 2 + getLongest(s, i + 1, j - 1);
    }
    
    return max(getLongest(s, i + 1, j), getLongest(s, i, j - 1));
}

// top down - better - O(n2)
int getLongest(string s, int i, int j, vector <vector <int>> dp) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    
    if (dp[i][j] == -1) {
        int m = 0;
        if (s[i] == s[j]) {
            dp[i][j] = 2 + getLongest(s, i + 1, j - 1);
        } else {
            dp[i][j] = max(getLongest(s, i + 1, j), 
                            getLongest(s, i, j - 1));
        }
    }
    
    return dp[i][j];
}

// bottom up - O(n2)
int getLongest(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int>(n, 0));
    
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

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector <vector <int>> dp(n, vector <int>(n, -1));
    return getLongest(s);
}

int main() {
    string s = "abdbca";
    int lps = longestPalindromeSubseq(s);
    cout << lps << endl;
    return 0;
}