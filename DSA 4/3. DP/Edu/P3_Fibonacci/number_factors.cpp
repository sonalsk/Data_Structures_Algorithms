#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int factors(int n) {
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    return factors(n - 1) + factors(n - 3) + factors (n - 4);
}

int factors(int n, vector <int> dp) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = factors(n - 1) + factors(n - 3) + factors (n - 4);
    return dp[n];
}

int getFactorsBU(int n) {
    vector <int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++) {        
        if (i <= 2) {
            dp[i] = 1;
        } else if (i == 3) {
            dp[i] = 2;
        } else {
            dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
        }
    }
    return dp[n];
}

int getFactors(int n) {
    return factors(n);
}

int main() {
    int n = 4;
    int factors = getFactors(n);
    cout << factors << endl;
    return 0;
}