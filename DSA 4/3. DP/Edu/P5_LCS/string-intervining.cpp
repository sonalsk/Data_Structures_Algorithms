#include <bits/stdc++.h>

using namespace std;

int find(string m, string n, string p, int i, int j, int k) {
    if (i == m.length() && j == n.length() && k == p.length()) {
        return true;
    }
    if (k == p.length()) {
        return false;
    }

    int takeM = false, takeN = false;
    if (i < m.length() && p[k] == m[i]) {
        takeM = find(m, n, p, i + 1, j, k + 1);
    }
    if (j < n.length() && p[k] == n[j]) {
        takeN = find(m, n, p, i, j + 1, k + 1);
    }

    return takeM || takeN;
}

bool findSI(string m, string n, string p) {
    vector<vector<bool>> dp(m.length() + 1, vector<bool>(n.length() + 1));

    if (m.length() + n.length() != p.length()) {
      return false;
    }

    for (int mIndex = 0; mIndex <= m.length(); mIndex++) {
      for (int nIndex = 0; nIndex <= n.length(); nIndex++) {
        if (mIndex == 0 && nIndex == 0) {
          dp[mIndex][nIndex] = true;
        }
        else if (mIndex == 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
          dp[mIndex][nIndex] = dp[mIndex][nIndex - 1];
        }
        else if (nIndex == 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
          dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
        } else {
          if (mIndex > 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
          }
          if (nIndex > 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex][nIndex] || dp[mIndex][nIndex - 1];
          }
        }
      }
    }
    return dp[m.length()][n.length()];
}


int main() {
    cout << findSI("abd", "cef", "abcdef") << endl;
    cout << findSI("abd", "cef", "adcbef") << endl;
    cout << findSI("abc", "def", "abdccf") << endl;
    cout << findSI("abcdef", "mnop", "mnaobcdepf") << endl;

    return 0;
}