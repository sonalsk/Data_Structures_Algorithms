#include <bits/stdc++.h>

using namespace std;

// Recursive - Exponential
int knapsack(vector <int> weights, vector <int> values, int w, int i) {
    if (i == -1 || w == 0) {
        return 0;
    }
    if (weights[i] <= w) {
        int inc = values[i] + knapsack(weights, values, w - weights[i], i - 1);
        int exc = knapsack(weights, values, w, i - 1);
        return max(inc, exc);
    }
    else {
        return knapsack(weights, values, w, i - 1);
    }   
}

// Top Down - Memoization - O(n * w)
int knapsackTopDown(vector <int> weights, vector <int> values, int w, int i, vector<vector<int>> &dp) {
    if (i == -1 || w == 0) {
        return 0;
    }
    if (dp[w][i] != -1) {
        return dp[w][i];
    }
    if (weights[i] <= w) {
        int inc = values[i] + knapsack(weights, values, w - weights[i], i - 1);
        int exc = knapsack(weights, values, w, i - 1);
        dp[w][i] = max(inc, exc);        
        return dp[w][i];
    }
    else {
        dp[w][i] = knapsack(weights, values, w, i - 1);
        return dp[w][i];
    }   
}

// Bottom Up - O(n * w)
int knapsackBottomUp(vector <int> weights, vector <int> values, int w) {
    vector <vector <int>> dp(w+1, vector <int>(weights.size() + 1, 0));
    
    for (int i = 1; i <= weights.size(); i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] <= j) {
                dp[j][i] = max(values[i] + dp[j - weights[i]][i - 1], dp[j][i - 1]);
            }
            else {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }

    return dp[w][weights.size()];
}

// Bottom Up - O(n * w)
int knapsackBottomUpReconstruct(vector <int> weights, vector <int> values, int w) {
    vector <vector <int>> dp(w+1, vector <int>(weights.size() + 1, 0));
    vector <vector <bool>> desc(w+1, vector <bool>(weights.size() + 1, false));

    for (int i = 1; i <= weights.size(); i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] <= j) {
                if (dp[j - weights[i - 1]][i - 1] + values[i - 1] > dp[j][i - 1]) {
                    desc[j][i] = true;
                    dp[j][i] = max(values[i] + dp[j - weights[i]][i - 1], dp[j][i - 1]);
                }
            }
            else {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }

    int i = weights.size();
    int j = w;

    while (i > 0 && j > 0) {
        bool picked = desc[j][i];
        if (picked) {
            cout << "Picked " << (i - 1) << " weight " << weights[i - 1] << " value " << values[i - 1] << endl;
            j -= weights[i - 1];
            i--;
        }
        else {
            i--;
        }
    }

    return dp[w][weights.size()];
}


int main() {
    vector <int> weights{3, 7, 10, 6};
    vector <int> values{4, 14, 10, 5};
    int w = 20;
    
    cout << knapsack(weights, values, w, weights.size() - 1) << endl;

    return 0;
}