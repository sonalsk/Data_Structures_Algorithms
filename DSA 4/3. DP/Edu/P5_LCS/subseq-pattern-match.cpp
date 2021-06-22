#include <bits/stdc++.h>

using namespace std;

int spm(string str, string pat, int i, int j) {
    if (j == pat.length()) {
        return 1;
    }

    if (i == str.length()) {
        return 0;
    }
    
    int inc = 0;
    if (str[i] == pat[j]) {
        inc = spm(str, pat, i + 1, j + 1);
    }

    int exc = spm(str, pat, i + 1, j);
    
    return inc + exc;
}

int spm(string str, string pat, int i, int j, vector<vector <int>> dp) {
    if (j == pat.length()) {
        return 1;
    }

    if (i == str.length()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int inc = 0;
    if (str[i] == pat[j]) {
        inc = spm(str, pat, i + 1, j + 1, dp);
    }

    int exc = spm(str, pat, i + 1, j, dp);
    
    dp[i][j] = inc + exc;
    return dp[i][j];
}

int spm(string str, string pat) {
    vector <vector<int>> dp(str.length() + 1, vector <int>(pat.length() + 1, 0));

    for (int i = 0; i < str.length() + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < str.length() + 1; i++) {
        for (int j = 1; j < pat.length() + 1; j++) {
            int inc = 0, exc = 0;
            if (str[i] == pat[j]) {
                inc = dp[i - 1][j - 1];
            }
            exc = dp[i - 1][j];
            
            dp[i][j] = inc + exc;
        }
    }

    return dp[str.length()][pat.length()];
}

int getTimes(string str, string pat) {
    vector <vector<int>> dp(str.length(), vector <int>(pat.length(), -1));
    return spm(str, pat);
}

int main() {
    string str = "baxmx";
    string pat = "ax";

    cout << getTimes("baxmx", "ax") << endl;
    cout << getTimes("tomorrow", "tor") << endl;

    return 0;
}