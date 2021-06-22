#include <bits/stdc++.h>
using namespace std;

// Given two integer arrays to represent weights and profits of ‘N’ items, 
// we need to find a subset of these items which will give us maximum 
// profit such that their cumulative weight is not more than a given number ‘C’. 
// Write a function that returns the maximum profit. 
// Each item can only be selected once, which means either we put an item in the knapsack or skip it.

// Recursive Approach -O(2^n)
int getKnapsack(vector <int> &profits, vector <int> &weights, int m, int i, int pft) {
    if (m < 0) {
        return 0;
    }
    if (i == profits.size()) {
        return pft;
    }

    int inc = getKnapsack(profits, weights, m - weights[i], i + 1, pft + profits[i]);
    int exc = getKnapsack(profits, weights, m, i + 1, pft);

    return max(inc, exc);
}

// Top Down DP - O(C * N)
int getKnapsack(vector <int> profits, vector <int> weights, int m, int i, int pft, vector <vector<int>> dp) {
    if (m < 0) {
        return 0;
    }
    if (i == profits.size()) {
        return pft;
    }
    if (dp[i][m] != -1) {
        return dp[i][m];
    }

    int inc = getKnapsack(profits, weights, m - weights[i], i + 1, pft + profits[i], dp);
    int exc = getKnapsack(profits, weights, m, i + 1, pft, dp);

    dp[i][m] = max(inc, exc);
    return dp[i][m];
}

// Bottom Up DP
// dp[i][c] will represent the maximum knapsack profit for capacity ‘c’ calculated from the first ‘i’ items
int getKnapsackBU(vector <int> profits, vector <int> weights, int capacity) {
    int n = profits.size();
    vector <vector <int>> dp(n, vector <int>(capacity + 1));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int c = 0; c <= capacity; c++) {
        if (weights[0] <= c) {
            dp[0][c] = profits[0];
        }
    }

    for (int c = 0; c <= capacity; c++) {
        if (weights[0] <= c) {
            dp[0][c] = profits[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= capacity; j++) {
            int inc = 0;
            int exc = 0;
            
            if (weights[i] <= j) {
                inc = profits[i] + dp[i - 1][j - weights[i]];
            }
            exc = dp[i - 1][j];
            dp[i][j] = max(inc, exc);
        }
    }

    return dp[n - 1][capacity];
}

int solveKnapsack(vector <int> &profits, vector <int> &weights, int m) {
    cout << getKnapsack(profits, weights, m, 0, 0) << endl;
    vector <vector <int>> dp(profits.size(), vector<int>(m + 1, -1));
    cout << getKnapsack(profits, weights, m, 0, 0, dp) << endl;
    cout << getKnapsackBU(profits, weights, m) << endl;
    return 0;
}

int main() {
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    
    int maxProfit = solveKnapsack(profits, weights, 7);
    cout << "Total knapsack profit ---> " << maxProfit << endl;
    maxProfit = solveKnapsack(profits, weights, 6);
    cout << "Total knapsack profit ---> " << maxProfit << endl;

    return 0;
}