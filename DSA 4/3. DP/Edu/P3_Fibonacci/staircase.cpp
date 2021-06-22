#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int getWays(int stairs) {
    if (stairs < 0) {
        return 0;
    }
    if (stairs == 0) {
        return 1;
    }
    
    return getWays(stairs - 1) + getWays(stairs - 2) + getWays(stairs - 3);
}

int getWays(int stairs, vector <int> dp) {
    if (stairs < 0) {
        return 0;
    }
    if (stairs == 0) {
        return 1;
    }
    if (dp[stairs] != -1) {
        return dp[stairs];
    }
    
    dp[stairs] = getWays(stairs - 1, dp) + getWays(stairs - 2, dp) + getWays(stairs - 3, dp);
    return dp[stairs];
}

int getWays(int stairs) {
    vector <int> dp(stairs + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= stairs; i++) {
        if (i <= 2) {
            dp[i] = i;
        } else {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }

    return dp[stairs];
}

int main() {
    int stairs = 3;
    int ways = getWays(stairs);
    cout << ways << endl;
    return 0;
}