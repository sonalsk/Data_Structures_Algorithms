#include <bits/stdc++.h>

using namespace std;

int jumpMin(vector <int> nums, int curr) {
    if (curr == nums.size() - 1) {
        return 0;
    }
    if (curr > nums.size() - 1) {
        return 0;
    }
    
    int m = INT_MAX - 1;
    for (int i = nums[curr]; i > 0; i--) {
        m = min(m, 1 + jumpMin(nums, curr + i));
    }
    
    return (int) m;
}

int jumpMin(vector <int> nums, int curr, vector <int> dp) {
    if (curr == nums.size() - 1) {
        return 0;
    }
    if (curr > nums.size() - 1) {
        return 0;
    }
    
    if (dp[curr] != -1) {
        return dp[curr];
    }
    
    int m = INT_MAX - 1;
    for (int i = nums[curr]; i > 0; i--) {
        m = min(m, 1 + jumpMin(nums, curr + i, dp));
    }
    
    dp[curr] = (int) m;
    return dp[curr];
}

int jumpBU(vector<int>& nums) {
    int n = nums.size();
    vector <int> dp(n, INT_MAX - 1);
    dp[n - 1] = 0;
    
    for (int curr = n - 2; curr >= 0; curr--) {            
        for (int i = 0; curr + i < n && i <= nums[curr]; i++) {
            dp[curr] = min(dp[curr] , 1 + dp[curr + i]);
        }
    }
    
    return dp[0];
}

int jumpBU2(vector<int>& nums) {
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        curFarthest = max(curFarthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}

int jump(vector<int>& nums) {
    vector <int> dp(nums.size(), -1);
    return jumpMin(nums, 0, dp);
}

int main() {
    return 0;
}