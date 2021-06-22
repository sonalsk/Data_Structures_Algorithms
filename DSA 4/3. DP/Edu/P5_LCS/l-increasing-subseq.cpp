#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int lis(vector <int> &nums, int curr, int prev) {
    if (curr >= nums.size()) {
        return 0;
    }
    int inc = 0;
    if (prev == -1 || nums[curr] > nums[prev]) {
        inc = 1 + lis(nums, curr + 1, curr);
    }
    int exc = lis(nums, curr + 1, prev);
    
    return max(inc, exc);
}

int lis(vector <int> &nums, int curr, int prev, vector <vector <int>> dp) {
    if (curr == nums.size()) {
        return 0;
    }
    
    if (dp[curr][prev + 1] != -1) {
        return dp[curr][prev + 1];
    }

    int inc = 0;
    if (prev == -1 || nums[curr] > nums[prev]) {
        inc = 1 + lis(nums, curr + 1, curr, dp);
    }
    int exc = lis(nums, curr + 1, prev, dp);
    
    dp[curr][prev + 1] = max(inc, exc);
    return dp[curr][prev + 1];
}

int lis(vector <int> nums) {
    vector <int> dp(nums.size());
    dp[0] = 1;

    int maxLength = 1;
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                maxLength = max(maxLength, dp[i]);
            }
        }
    }
    
    return maxLength;
}


void getList(vector <int> nums) {
    vector <vector <int>> dp(nums.size(), vector <int>(nums.size() + 1, -1));
    cout << lis(nums, 0, -1) << endl;
}

int main() {
    vector <int> arr = {4, 2, 3, 6, 10, 1, 12};
    getList(arr);
    return 0;
}