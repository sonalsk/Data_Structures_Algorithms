#include <bits/stdc++.h>

using namespace std;

// Backtracking - All colours
int minimumCostBTAll(vector <vector<int>> cost, int house, int c) {
    if (house >= cost.size()) {
        return c;
    }

    int f = minimumCostBTAll(cost, house + 1, c + cost[house][0]);
    int s = minimumCostBTAll(cost, house + 1, c + cost[house][1]);
    int t = minimumCostBTAll(cost, house + 1, c + cost[house][2]);
    
    return min(min(f, s), t);
}

// Backtracking - No adjacent same
int minimumCostBT(vector <vector<int>> cost, int house, int color) {
    if (house == cost.size()) {
        return 0;
    }
    if (color == 0) {
        return cost[house][color] + min(minimumCostBT(cost, house + 1, 1), minimumCostBT(cost, house + 1, 2));
    }
    else if (color == 1) {
        return cost[house][color] + min(minimumCostBT(cost, house + 1, 0), minimumCostBT(cost, house + 1, 2));
    }
    else if (color == 2) {
        return cost[house][color] + min(minimumCostBT(cost, house + 1, 0), minimumCostBT(cost, house + 1, 1));
    }
    return 0;
}

// Top Down
int minimumCostTD(vector <vector<int>> cost, int house, int color, vector <vector <int>> dp) {
    if (house == cost.size()) {
        return 0;
    }
    if (dp[house][color] != -1) {
        return dp[house][color];
    }
    if (color == 0) {
        dp[house][color] = cost[house][color] + min(minimumCostTD(cost, house + 1, 1, dp), minimumCostTD(cost, house + 1, 2, dp));
        return dp[house][color];
    }
    else if (color == 1) {
        dp[house][color] = cost[house][color] + min(minimumCostTD(cost, house + 1, 0, dp), minimumCostTD(cost, house + 1, 2, dp));
        return dp[house][color];
    }
    else if (color == 2) {
        dp[house][color] = cost[house][color] + min(minimumCostTD(cost, house + 1, 0, dp), minimumCostTD(cost, house + 1, 1, dp));
        return dp[house][color];
    }
    return 0;
}

int minimumCost(vector<vector<int>> &cost) {
    int red = minimumCostBT(cost, 0, 0);
    int blue = minimumCostBT(cost, 0, 1);
    int green = minimumCostBT(cost, 0, 2);
    cout << min(min(red, blue), green) << endl;

    vector <vector <int>> dp(cost.size(), vector<int>(cost[0].size(), -1));

    red = minimumCostTD(cost, 0, 0, dp);
    blue = minimumCostTD(cost, 0, 1, dp);
    green = minimumCostTD(cost, 0, 2, dp);
    cout << min(min(red, blue), green) << endl;

    return 0;
}

int main() {
    // i = index of the house
    // c = color of the paint (0, 1, 2)

    // cost function - min_cost(i, c) - returns the minimum cost of painting house i with paint color c
    
    // min_cost(i, RED) = cost[i][RED] + min(min_cost(i, BLUE), min_cost(i, GREEN))
    // min_cost(i, BLUE) = cost[i][BLUE] + min(min_cost(i, RED), min_cost(i, GREEN))
    // min_cost(i, GREEN) = cost[i][GREEN] + min(min_cost(i, BLUE), min_cost(i, RED))

    vector <vector <int>> cost = {{17, 2, 17}, {16, 16, 5}, {14, 3, 9}};
    cout << minimumCost(cost) << endl;
    return 0;
}