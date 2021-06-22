#include <bits/stdc++.h>
using namespace std;

// Finding the nth Fibonacci number

// Recursive Approach
int nthFiboNum(int n) {
    if (n <= 1) {
        return n;
    }
    return nthFiboNum(n - 1) + nthFiboNum(n - 2);
}

// Top Down DP
int nthFiboNum(int n, vector <int> dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = nthFiboNum(n - 1, dp) + nthFiboNum(n - 2, dp);
    return dp[n];
}

// Bottom Up DP
int nthFiboNumBU(int n) {
    vector <int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

void nthFibo(int n) {
    cout << nthFiboNum(n) << endl;
    vector <int> dp(n + 1, -1);
    cout << nthFiboNum(n, dp) << endl;
    cout << nthFiboNumBU(n) << endl;
}

int main() {
    int n = 6;
    nthFibo(n);
    return 0;
}