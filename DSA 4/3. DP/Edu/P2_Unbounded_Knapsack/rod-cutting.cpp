#include <bits/stdc++.h>
using namespace std;

// Given a rod of length ‘n’, we are asked to cut the rod and 
// sell the pieces in a way that will maximize the profit. 
// We are also given the price of every piece of length ‘i’ where ‘1 <= i <= n’.

int getCutRod(vector <int> lengths, vector <int> prices, int curr, int rod) {
    if (rod <= 0 || curr >= lengths.size()) {
        return 0;
    }
    int inc = 0;
    if (lengths[curr] <= rod) {
        inc = prices[curr] + getCutRod(lengths, prices, curr, rod - lengths[curr]);
    }

    int exc = getCutRod(lengths, prices, curr + 1, rod);
    return max(inc, exc);
}

int getCutRod(vector <int> lengths, vector <int> prices, int curr, int rod, vector <vector<int>> dp) {
    if (rod <= 0 || curr >= lengths.size()) {
        return 0;
    }
    if (dp[curr][rod] == -1) {
        int inc = 0;
        if (lengths[curr] <= rod) {
            inc = prices[curr] + getCutRod(lengths, prices, curr, rod - lengths[curr], dp);
        }

        int exc = getCutRod(lengths, prices, curr + 1, rod, dp);
        dp[curr][rod] = max(inc, exc);
    }
    return dp[curr][rod];
}

int getRod(vector <int> lengths, vector <int> prices, int n) {
    vector <vector<int>> dp(lengths.size(), vector <int>(n + 1, -1));
    return getCutRod(lengths, prices, 0, n);
}

int main() {
    vector <int> lengths = {1, 2, 3, 4, 5};
    vector <int> prices = {2, 6, 7, 10, 13};
    int rod = 5;

    getRod(lengths, prices, 5);
    return 0;
}