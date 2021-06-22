#include <bits/stdc++.h>

using namespace std;

// O(2^n) - Recursive
int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// O(n) - Top Down
int fibo(int n, unordered_map <int, int> dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n]) {
        return dp[n];
    }
    dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    return dp[n];
}

// O(n) - Bottom Up
int fibo(int n) {
    vector <int> fiboNum(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        if (i <= 1) {
            fiboNum[i] = i;
        } else {
            fiboNum[i] = fiboNum[i - 1] + fiboNum[i - 2];
        }
    }
    return fiboNum[n];
}

int main() {
    int n = 6;
    unordered_map <int, int> dp;
    cout << fibo(n) << endl;
    return 0;
}