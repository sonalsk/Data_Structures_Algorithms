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
int getSumSubset(vector <int> nums, int sum, int i) {
    if (sum == 0) {
        return 1;
    }
    if (i == nums.size()) {
        return 0;
    }
    int a = 0;
    if (nums[i] <= sum) {
        a = getSumSubset(nums, sum - nums[i], i + 1);
    }
    int b = getSumSubset(nums, sum, i + 1);

    return a + b;
}

// Top Down
int getSumSubset(vector <int> nums, int sum, int i, vector <vector <int>> dp) {
    if (sum == 0) {
        return 1;
    }
    
    if (i == nums.size()) {
        return 0;
    }
    
    if (dp[i][sum] == -1) {
        int a = 0;
        if (nums[i] <= sum) {
            a = getSumSubset(nums, sum - nums[i], i + 1, dp);
        }
        int b = getSumSubset(nums, sum, i + 1, dp);
        dp[i][sum] = a + b;
    }

    return dp[i][sum];
}


void getSubset(vector <int> &nums, int sum) {
    // vector <int> set;
    // getAllSubset(nums, 0, set);
    
    // int n = nums.size();
    // vector<vector<bool>> dp(n, vector<bool>(sum + 1, -1));
    cout << getSumSubset(nums, sum, 0) << endl;
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