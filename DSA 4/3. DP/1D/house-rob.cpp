#include <bits/stdc++.h>

using namespace std;

// recursion - O(2^n)
int getMaxProfit(vector <int> &s, int i) {
    if (i < 0) {
        return 0;
    }
    return max(s[i] + getMaxProfit(s, i - 2), getMaxProfit(s, i - 1));
}

// top down - O(N)
int getMaxProfit(vector <int> &s, int i, vector <int> dp) {
    if (i < 0) {
        return 0;
    }
    if (dp[i]) {
        return dp[i];
    }
    dp[i] = max(s[i] + getMaxProfit(s, i - 2, dp), getMaxProfit(s, i - 1, dp));
    return dp[i];
}

// bottom up - O(N)
int getMaxProfitBU(vector <int> &s) {
    vector <int> dp(s.size() + 1, 0);
    
    dp[1] = s[0];
    for (int i = 2; i <= s.size(); i++) {
        dp[i] = max(s[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[s.size()];
}

// Reconstruct
int getMaxProfitRec(vector <int> &s) {
    vector <int> dp(s.size() + 1, 0);
    vector <bool> rob(s.size(), false);
    
    dp[1] = s[0];
    rob[0] = true;
    for (int i = 2; i <= s.size(); i++) {
        if (s[i] + dp[i - 2] > dp[i - 1]) {
            dp[i] = s[i] + dp[i - 2];
            rob[i - 1] = true;
        }
        else {
            dp[i] = dp[i - 1];
            rob[i - 1] = false;
        }
    }

    int i = s.size() - 1;
    while (i >= 0) {
        if (rob[i]) {
            cout << s[i] << " ";
            i = i - 2;
        }
        else {
            i--;
        }
    }
    
    return dp[s.size()];
} 

void getMaxProfit(vector <int> &s) {
    vector <int> dp(s.size(), 0);
    cout << getMaxProfitBU(s) << endl;
}

int main() {
    vector <int> s = {20, 25, 30, 15, 10};
    getMaxProfit(s);
    return 0;
}