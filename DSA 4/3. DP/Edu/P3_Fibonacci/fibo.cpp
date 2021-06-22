#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int getFibo(int n) {
    if (n <= 1) {
        return n;
    }
    return getFibo(n - 1) + getFibo(n - 2);
}

int getFibo(int n, vector <int> dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = getFibo(n - 1, dp) + getFibo(n - 2, dp);
    return dp[n];
}

int getFiboBU(int n) {
    vector <int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i <= 1) {
            dp[i] = i;
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    return dp[n];
}

int CalculateFibonacci(int n) {
    vector <int> dp(n + 1, -1);
    return getFibo(n, dp);
}

int main() {
    int n = 6;
    int nthFib = CalculateFibonacci(n);
    cout << nthFib << endl;
    return 0;
}