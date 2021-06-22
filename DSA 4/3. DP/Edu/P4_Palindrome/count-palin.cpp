#include <bits/stdc++.h>
using namespace std;

int findLPSLength(const string &st) {
    vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));
    int count = 0;

    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = true;
      count++;
    }    

    for (int i = st.length() - 1; i >= 0; i--) {
        for (int j = i + 1; j < st.length(); j++) {
            
            if (st[i] == st[j]) {
                int remain = j - i - 1;
                
                if (remain == 0 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
    }

    return count;
}

int longestPalindrome(string s) {
    vector <vector <int>> dp(s.length(), vector <int>(s.length(), -1));
    // return getSubs(s, 0, s.length() - 1, dp);
    return findLPSLength(s);
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