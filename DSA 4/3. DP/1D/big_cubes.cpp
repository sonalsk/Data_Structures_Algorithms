#include <bits/stdc++.h>

using namespace std;

// starting from index 0
int getMinS(vector <int> &cost, int x, int curr) {
    if (curr > cost.size()) {
        return 0;
    }
    if (curr == cost.size() - 1) {
        return (cost[curr]);
    }
    int m = INT_MAX;
    int left = cost.size() - curr - 1;
    for (int i = 1; i <= min(x, left); i++) {
        m = min(m, cost[curr] + getMinS(cost, x, curr + i));
    }    
    return m;
}

int getMinRBU(vector <int> &cost, int x) {
    vector <int> dp(cost.size(), 0);
    dp[0] = cost[0];

    for (int i = 1; i < cost.size(); i++) {
        int left = i;
        int m = INT_MAX;

        for (int j = 1; j <= min(x, left); j++) {
            m = min(m, cost[i] + dp[i - j]);
        }

        dp[i] = m;
    }

    return dp[cost.size() - 1];
}

// recursion
int getMin(vector <int> &cost, int x, int curr) {
    if (curr == 0) {
        return cost[curr];
    }
    int m = INT_MAX;
    for (int i = 1; i <= min(x, curr); i++) {
        m = min(m, cost[curr] + getMin(cost, x, curr - i));
    }    
    return m;
}
// top down
int getMinTD(vector <int> &cost, int x, int curr, vector <int> &dp) {
    if (curr == 0) {
        return cost[curr];
    }
    if (dp[curr]) {
        return dp[curr];
    }
    int m = INT_MAX;
    for (int i = 1; i <= min(x, curr); i++) {
        m = min(m, cost[curr] + getMinTD(cost, x, curr - i, dp));
    }
    dp[curr] = m;
    return dp[curr];
}
// bottom up
int getMinBU(vector <int> &cost, int x) {
    vector <int> dp(cost.size(), 0);
    dp[0] = cost[0];

    for (int i = 1; i < cost.size(); i++) {
        int m = INT_MAX;
        for (int j = 1; j <= min(x, i); j++) {
            m = min(m, cost[i] + dp[i - j]);
        }
        dp[i] = m;
    }
    return dp[cost.size() - 1];
}

int getMinRec(vector <int> &cost, int x) {
    vector <int> dp(cost.size(), 0);
    vector <int> jump(cost.size(), 0);
    dp[0] = cost[0];

    for (int i = 1; i < cost.size(); i++) {
        int m = INT_MAX;
        for (int j = 1; j <= min(x, i); j++) {
            if (dp[i - j] + cost[i] < dp[i]) {
                jump[i] = i - j;
                dp[i] = dp[i - j] + cost[i];
            }
        }
    }

    int i = cost.size() - 1;
    cout << i << " ";
    while (i > 0) {
        i = jump[i];
        cout << i << " ";
    }
    cout << endl;
    
    return dp[cost.size() - 1];
}

void getMinCost(vector <int> &cost, int x) {
    vector <int> dp(cost.size(), 0);
    cout << getMinRec(cost, x);
}

int main()  {
    vector <int> cost = {20, 30, 40, 25, 15, 20, 28};
    int x = 3;
    getMinCost(cost, x);

    cout << endl;
    return 0;
}