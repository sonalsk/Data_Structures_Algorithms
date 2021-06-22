#include <bits/stdc++.h>
using namespace std;

// Given a set of positive numbers, find if we can 
// partition it into two subsets such that the sum of 
// elements in both the subsets is equal.

int getSum(vector <int> arr) {
    int s = 0;
    for (int i: arr) {
        s += i;
    }
    return s;
}

bool canPartition(vector <int> arr, int i, vector <int> s, int ts) {
    if (i == arr.size()) {       
        return getSum(s) == (ts/2);
    }

    s.push_back(arr[i]);
    bool inc = canPartition(arr, i + 1, s, ts);
    s.pop_back();
    bool exc = canPartition(arr, i + 1, s, ts);

    return inc || exc;
}

// recursion
bool canPartition(vector <int> arr, int i, int ts) {
    if (ts == 0) {
        return true;
    }
    if (i == arr.size()) {       
        return false;
    }
    if (arr[i] <= ts) {
        if (canPartition(arr, i + 1, ts - arr[i])) {
            return true;
        }
    }
    return canPartition(arr, i + 1, ts);
}

// Top Down DP
bool canPartition(vector <int> arr, int i, int ts, vector <vector<int>> dp) {
    if (ts == 0) {
        return true;
    }
    if (i == arr.size()) {       
        return false;
    }
    if (dp[i][ts] == -1) {
        if (arr[i] <= ts) {
            if (canPartition(arr, i + 1, ts - arr[i], dp)) {
                dp[i][ts] = 1;
                return true;
            }
        }
        dp[i][ts] = canPartition(arr, i + 1, ts, dp) ? 1 : 0;
    }
    return dp[i][ts] == 1 ? true : false;
}

// Bottom Up DP
bool canPartitionBU(vector<int> &num) {
    int n = num.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += num[i];
    }

    if (sum % 2 != 0) {
        return false;
    }

    sum /= 2;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    for (int s = 1; s <= sum; s++) {
        dp[0][s] = (num[0] == s ? true : false);
    }

    for (int i = 1; i < n; i++) {
        for (int s = 1; s <= sum; s++) {
        if (dp[i - 1][s]) {
            dp[i][s] = dp[i - 1][s];
        }
        else if (s >= num[i]) {
            dp[i][s] = dp[i - 1][s - num[i]];
        }
        }
    }

    return dp[n - 1][sum];
}

bool canPartition(vector <int> arr) {
    int ts = getSum(arr);
    if (ts % 2 != 0) return false;
    return canPartition(arr, 0, ts / 2);
}

int main() {
    vector <int> arr = {2, 3, 4, 6};
    cout << canPartition(arr) << endl;
    return 0;
}