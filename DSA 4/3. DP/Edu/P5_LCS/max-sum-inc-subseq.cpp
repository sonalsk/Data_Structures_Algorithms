#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// O(2^n)
int lis(vector <int> arr, int curr, int prev) {
    if (curr == arr.size()) {
        return 0;
    }

    int inc = 0;
    if (prev == -1 || arr[prev] < arr[curr]) {
        inc = arr[curr] + lis(arr, curr + 1, curr);
    }
    int exc = lis(arr, curr + 1, prev);

    return max(inc, exc);
}

// O(n^2)
int lis(vector <int> arr, int curr, int prev, int sum, vector <vector <int>> dp) {
    if (curr == arr.size()) {
        return sum;
    }

    if (dp[curr][prev] != -1) {
        return dp[curr][prev];
    }

    int inc = 0;
    if (prev == -1 || arr[prev] < arr[curr]) {
        inc = lis(arr, curr + 1, sum + arr[curr], curr, dp);
    }
    int exc = lis(arr, curr + 1, sum, prev, dp);

    dp[curr][prev] = max(inc, exc);
    return dp[curr][prev];
}

// O(n^2)
int lis(vector <int> nums) {
    vector <int> dp(nums.size());
    dp[0] = nums[0];

    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = nums[i];
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + nums[i]) {
                dp[i] = dp[j] + nums[i];
                maxSum = max(maxSum, dp[i]);
            }
        }
    }
    
    return maxSum;
}

int mlis(vector <int> nums) {
    vector <vector <int>> dp(nums.size(), vector <int>(nums.size(), -1));
    return lis(nums, 0, -1, 0, dp);
}

int main() {
    vector <int> nums = {-4, 10, 3, 7, 15};
    int getMaxSum = mlis(nums);
    cout << getMaxSum << endl;
    return 0;
}