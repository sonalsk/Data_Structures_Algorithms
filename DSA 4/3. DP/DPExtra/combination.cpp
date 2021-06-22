#include <bits/stdc++.h>

using namespace std;

// O(2^n) - Recursive
int combinationRec(int n, int k) {
    if ((n == k) || (k == 0)) {
        return 1;
    }
    return combinationRec(n - 1, k - 1) + combinationRec(n - 1, k);
}

// O(n) - Top Down
int combinationTopDown(int n, int k, vector <vector<int>> dp) {
    if ((n == k) || (k == 0)) {
        return 1;
    }
    if (dp[n][k] != 0) {
        return dp[n][k];
    }
    dp[n][k] = combinationTopDown(n - 1, k - 1, dp) + combinationTopDown(n - 1, k, dp);
    return dp[n][k];
}

// Bottom Up
int combinationBottomUp(int n, int k) {
    vector <vector <int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        if (i <= k) {
            dp[i][i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

void combination(int n, int k) {
    cout << combinationRec(n, k) << endl;

    vector <vector <int>> dp(n + 1, vector<int>(k + 1, 0));
    cout << combinationTopDown(n, k, dp) << endl;

    cout << combinationBottomUp(n, k) << endl;
}

int main() {
    // nCk = n! / (n - k)! k!
    
    // C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
    // C(n, n) = 1, C(n, 0) = 1

    int n = 5;
    int k = 3;
    combination(n, k);
    return 0;
}