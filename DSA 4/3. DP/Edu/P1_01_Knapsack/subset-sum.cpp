#include <bits/stdc++.h>

using namespace std;

// Given a set of positive numbers, determine if 
// there exists a subset whose sum is equal to a given number ‘S’.

void print(vector <int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void getAllSubset(vector <int> &nums, int i, vector <int> set) {
    if (i == nums.size()) {
        print(set);
        return;
    }
    set.push_back(nums[i]);
    getAllSubset(nums, i + 1, set);
    set.pop_back();
    getAllSubset(nums, i + 1, set);
}

// Recursion - O(2^n)
bool getSumSubset(vector <int> nums, int sum, int i) {
    if (sum == 0) {
        return true;
    }
    if (i == nums.size()) {
        return false;
    }
    if (nums[i] <= sum) {
        if (getSumSubset(nums, sum - nums[i], i + 1)) {
            return true;
        }
    }
    return getSumSubset(nums, sum, i + 1);
}

// Top Down - O(n * s)
bool getSumSubset(vector <int> nums, int sum, int i, vector <vector<bool>> dp) {
    if (sum == 0) {
        return true;
    }
    if (i == nums.size()) {
        return false;
    }
    if (dp[i][sum] != -1) {
        if (nums[i] <= sum) {
            if (getSumSubset(nums, sum - nums[i], i + 1, dp)) {
                dp[i][sum] = 1;
                return true;
            }
        }
        dp[i][sum] = getSumSubset(nums, sum, i + 1, dp) ? 1 : 0;
    }
    
    return dp[i][sum] == 1 ? true : false;
}

// Bottom Up - O(n * s)
bool getSubsetBU(vector <int> &nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1));
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }

    for (int s = 1; s <= sum; s++) {
      dp[0][s] = (nums[0] == s ? true : false);
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int s = 1; s <= sum; s++) {
            if (dp[i - 1][s]) {
                dp[i][s] = dp[i - 1][s];
            } else if (s >= nums[i]) {
                dp[i][s] = dp[i - 1][s - nums[i]];
            }
        }
    }
    return dp[nums.size() - 1][sum];
}

void getSubset(vector <int> &nums, int sum) {
    // vector <int> set;
    // getAllSubset(nums, 0, set);
    
    // int n = nums.size();
    // vector<vector<bool>> dp(n, vector<bool>(sum + 1, -1));
    // cout << getSumSubset(nums, sum, 0, dp) << endl;

    cout << getSubsetBU(nums, sum) << endl;
}

int main() {
    vector <int> nums = {1, 2, 3, 7};
    vector <int> numss = {1, 2, 7, 1, 5};
    vector <int> numsss = {1, 3, 4, 8};
    getSubset(nums, 6);
    getSubset(numss, 10);
    getSubset(numsss, 6);
    return 0;
}