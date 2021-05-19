#include <bits/stdc++.h>

using namespace std;

// my attempt - recursion - exponential
int getMinCost(vector <int> &cost, int l) {
    if (l == 1) {
        return cost[l];
    }

    for (int i = 1; i <= l / 2; i++) {
        cost[l] = max(cost[l], (getMinCost(cost, l - i) + getMinCost(cost, i)));
    }

    return cost[l];
}

// video attempt
int getMinCostVideo(vector <int> &cost, int l) {
    if (l == 0) {
        return 0;
    }

    int m = INT_MIN;
    for (int i = 0; i < l; i++) {
        m = max(m, cost[i] + getMinCostVideo(cost, l - i - 1));
    }

    return m;
}

// top Down
int getMinCostTD(vector <int> &cost, int l, vector <int> dp) {
    if (l == 1) {
        return cost[l];
    }
    if (dp[l]) {
        return dp[l];
    }

    for (int i = 1; i <= l / 2; i++) {
        cost[l] = max(cost[l], (getMinCostTD(cost, l - i, dp) + getMinCostTD(cost, i, dp)));
        dp[l] = cost[l];
    }

    return dp[l];
}

// video attempt
int getMinCostVideoTD(vector <int> &cost, int l, vector <int> dp) {
    if (l == 0) {
        return 0;
    }

    if (dp[l]) {
        return dp[l];
    }

    int m = INT_MIN;
    for (int i = 0; i < l; i++) {
        m = max(m, cost[i] + getMinCostVideoTD(cost, l - i - 1, dp));
    }

    dp[l] = m;
    return m;
}

// bottom Up - O(n2)
int getMinCostBU(vector <int> &cost, int l) {
    vector <int> dp(l + 1, 0);
    dp[1] = cost[1];

    for (int i = 2; i <= l; i++) {
        for (int j = 1; j <= i / 2; j++) {
            cost[i] = max(cost[i], (dp[i - j] + dp[j]));
            dp[i] = cost[i];
        }
    }
    
    return dp[l];
}

// video attempt - O(n2)
int getMinCostBUVideo(vector <int> &cost, int l) {
    vector <int> dp(l + 1, 0);

    for (int i = 1; i <= l; i++) {
        dp[i] = INT_MIN;
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], cost[j] + dp[i - j - 1]);
        }
    }
    
    return dp[l];
}

int getMinCostRecons(vector <int> &cost, int L) {
    vector <int> dp(L + 1, 0);
    vector <int> cuts(L + 1, 0);

    for (int l = 1; l <= L; l++) {
        dp[l] = INT_MIN;
        int cut = -1;
        for (int i = 0; i < l; i++) {
            if (cost[i] + dp[l - i - 1] > dp[l]) {
                dp[l] = cost[i] + dp[l - i - 1];
                cut = i + 1;
            }
        }
        cuts[l] = cut;
    }

    int l = L;
    int cut = cuts[L];
    while (cut != 0) {
        cout << cut << " ";
        l = l - cut;
        cut = cuts[l];
    }
    
    return dp[L];
}

int getCost(vector <int> &cost, int l) {
    vector <int> dp(l + 1, 0);
    return getMinCostBU(cost, l);
}

int main() {
    vector <int> cost = {0, 2, 2, 2, 3, 5, 7};
    int l = 6;
    cout << getCost(cost, l) << endl;
    return 0;
}