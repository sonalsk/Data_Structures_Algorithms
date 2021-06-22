#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Given two integer arrays to represent weights and profits of ‘N’ items, 
// we need to find a subset of these items which will give us maximum profit 
// such that their cumulative weight is not more than a given number ‘C’. 
// We can assume an infinite supply of item quantities; 
// therefore, each item can be selected multiple times.

int getMaxProfit(vector <int> weights, vector <int> profits, int cap, int start) {
    if (cap <= 0 || start >= profits.size()) {
        return 0;
    }
    int inc = 0;
    if (weights[start] <= cap) {
        inc = profits[start] + getMaxProfit(weights, profits, cap - weights[start], start);
    }
    return max(inc, getMaxProfit(weights, profits, cap, start + 1));
}

int getMaxProfitTD(vector <int> weights, vector <int> profits, int cap, int start, vector <vector <int>> dp) {
    if (cap <= 0 || start >= profits.size()) {
        return 0;
    }

    if (dp[start][cap] != -1) {
        return dp[start][cap];
    }

    int inc = 0;
    if (weights[start] <= cap) {
        inc = profits[start] + getMaxProfitTD(weights, profits, cap - weights[start], start, dp);
    }

    dp[start][cap] = max(inc, getMaxProfitTD(weights, profits, cap, start + 1, dp));
    return dp[start][cap];
}

int getMaxProfitBU(vector <int> weights, vector <int> profits, int cap) {
    int n = weights.size();
    vector <vector<int>> dp(n, vector <int> (cap + 1, -1));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < cap + 1; j++) {
            int inc = 0, exc = 0;
            if (weights[i] <= cap) {
                inc = profits[i] + dp[i][j - weights[i]];
            }

            if (i > 0) {
                exc = dp[i - 1][j];
            }

            dp[i][j] = max(inc, exc);
        }
    }

    return dp[n - 1][cap];
}

int getProfit (vector <int> weights, vector <int> profits, int capacity) {
    vector <int> sub;
    cout << getMaxProfit(weights, profits, capacity, 0);
    return 0;
}

int main() {
    vector <int> weights = {1, 2, 3};
    vector <int> profits = {15, 20, 50};
    int capacity = 5;

    int prof = getProfit(weights, profits, capacity);
    cout << "\n" << prof << endl;

    return 0;
}