#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int getMoney(vector <int> nums, int curr) {
    if (curr >= nums.size()) {
        return 0;
    }
    
    int rob = nums[curr] + getMoney(nums, curr + 2);
    int dontRob = getMoney(nums, curr + 1);
    
    return max(rob, dontRob);
}

int getMoney(vector <int> nums, int curr, vector <int> dp) {
    if (curr >= nums.size()) {
        return 0;
    }
    
    if (dp[curr] == 0) {
    
        int rob = nums[curr] + getMoney(nums, curr + 2, dp);
        int dontRob = getMoney(nums, curr + 1, dp);

        dp[curr] = max(rob, dontRob);
    }
    
    return dp[curr];
}

int getMoney(vector <int> nums) {
    vector <int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];      

    for (int i = 1; i < nums.size(); i++) {
        dp[i + 1] = max(nums[i] + dp[i - 1], dp[i]);
    }

    return dp[nums.size()];
}

int rob(vector<int>& nums) {
    vector <int> dp(nums.size(), 0);
    int maxMoney = getMoney(nums);
    return maxMoney;
}

    
int main() {
    return 0;
}