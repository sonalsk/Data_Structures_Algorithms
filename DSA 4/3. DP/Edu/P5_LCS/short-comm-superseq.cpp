#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// O(2^(n + m))
int scs(string a, string b, int i, int j) {
    if (i == a.length()) {
        return b.length() - j;
    }
    if (j == b.length()) {
        return a.length() - i;    
    }

    if (a[i] == b[j]) {
        return 1 + scs(a, b, i + 1, j + 1);
    }

    int skipA = 1 + scs(a, b, i + 1, j);
    int skipB = 1 + scs(a, b, i, j + 1);
    
    return min(skipA, skipB);
}

// O(n*m)
int scs(string a, string b, int i, int j, vector <vector <int>> dp) {
    if (i == a.length()) {
        return b.length() - j;
    }
    if (j == b.length()) {
        return a.length() - i;    
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        dp[i][j] = 1 + scs(a, b, i + 1, j + 1);
    }

    int skipA = 1 + scs(a, b, i + 1, j);
    int skipB = 1 + scs(a, b, i, j + 1);
    
    dp[i][j] = min(skipA, skipB);

    return dp[i][j];
}

// O(n*m)
int scs(string a, string b) {
    vector <vector <int>> dp(a.length() + 1, vector <int> (b.length() + 1));

    for (int i = 1; i < a.length() + 1; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i < b.length() + 1; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i < a.length() + 1; i++) {
        for (int j = 1; j < b.length() + 1; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[a.length()][b.length()];
}

int getSuperSeq(string s1, string s2) {
    return scs(s1, s2);
}

int main() {
    string s1 = "dynamic";
    string s2 = "programming";

    int scseq = getSuperSeq(s1, s2);
    cout << scseq << endl;

    return 0;
}