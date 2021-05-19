#include <bits/stdc++.h>

using namespace std;

void print(vector <int> &path) {
    for (int i: path) {
        cout << i << " ";
    }
    cout << endl;
}

void allPaths(vector <vector <int>> &grid, int i, int j, vector <int> path) {
    path.push_back(grid[i][j]);
    if (i == grid.size() - 1 && j == grid.size() - 1) {
        print(path);
        return;
    }
    if (j < grid[0].size() - 1) {
        allPaths(grid, i, j + 1, path);
    }
    if (i < grid.size() - 1) {
        allPaths(grid, i + 1, j, path);
    }
}

int recursive(vector <vector <int>> &grid, int i, int j) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    int m = INT_MAX;
    if (j > 0) {
        m = grid[i][j] + recursive(grid, i, j - 1);
    }
    if (i > 0) {
        int s = grid[i][j] + recursive(grid, i - 1, j);
        m = min(m, s);
    }
    return m;
}

int topDown(vector <vector <int>> &grid, int i, int j, vector <vector<int>> dp) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (dp[i][j]) {
        return dp[i][j];
    }
    int m = INT_MAX;
    if (j > 0) {
        m = grid[i][j] + topDown(grid, i, j - 1, dp);
    }
    if (i > 0) {
        int s = grid[i][j] + topDown(grid, i - 1, j, dp);
        m = min(m, s);
    }
    dp[i][j] = m;
    return dp[i][j];
}

int bottomUp(vector <vector <int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();

    vector <vector <int>> dp(r, vector <int>(c, 0));
    dp[0][0] = grid[0][0];
    
    for (int i = 1; i < c; i++) {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < r; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[r - 1][c - 1];
}

void minCostPath(vector <vector <int>> &grid) {
    vector <int> path;
    allPaths(grid, 0, 0, path);
    
    int r = grid.size();
    int c = grid[0].size();

    vector <vector <int>> dp(grid.size(), vector <int>(grid[0].size(), 0));
    
    cout << recursive(grid, r - 1, c - 1) << endl;
    cout << topDown(grid, r - 1, c - 1, dp) << endl;
    cout << bottomUp(grid) << endl;
}

int main() {

    // you are given a grid. you start at (0,0), top-left corner and you have to reach bottom left corner.
    // You can only move down or right. Find out the min cost to reach the destination.
    vector <vector <int>> grid = {{0, 47, 8, 18, 1},
                                  {43, 25, 39, 36, 13},
                                  {22, 8, 13, 38, 46},
                                  {41, 41, 40, 25, 44},
                                  {29, 43, 22, 50, 10}};

    // vector <vector <int>> grid = {{0, 47, 8},
    //                               {43, 25, 39},
    //                               {22, 8, 13}};
    minCostPath(grid);
    return 0;
}