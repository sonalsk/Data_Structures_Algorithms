// Given a number sequence, find the length of its Longest Alternating Subsequence (LAS).
// A subsequence is considered alternating if its elements are in alternating order.
// A three element sequence (a1, a2, a3) will be an alternating sequence if its 
// elements hold one of the following conditions: {a1 > a2 < a3 } or { a1 < a2 > a3}.

#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int las(vector <int> arr, int curr, int prev, bool isInc) {
    if (curr == arr.size()) {
        return 0;
    }

    int inc = 0;
    if (isInc) {
        if (prev == -1 || arr[curr] > arr[prev]) {
            inc = 1 + las(arr, curr + 1, curr, !isInc);
        }
    } else {
        if (prev == -1 || arr[curr] < arr[prev]) {
            inc = 1 + las(arr, curr + 1, curr, !isInc);
        }
    }

    int exc = las(arr, curr + 1, prev, isInc);

    return max(inc, exc);
}

int las(vector <int> arr, int curr, int prev, bool isInc, vector <vector <vector<int>>> dp) {
    if (curr == arr.size()) {
        return 0;
    }

    if(dp[prev + 1][curr][isInc ? 1 : 0] == -1) {
        int inc = 0;
        if (isInc) {
            if (prev == -1 || arr[curr] > arr[prev]) {
                inc = 1 + las(arr, curr + 1, curr, !isInc, dp);
            }
        } else {
            if (prev == -1 || arr[curr] < arr[prev]) {
                inc = 1 + las(arr, curr + 1, curr, !isInc, dp);
            }
        }

        int exc = las(arr, curr + 1, prev, isInc, dp);
        dp[prev + 1][curr][isInc ? 1 : 0] = max(inc, exc);
    }

    return dp[prev + 1][curr][isInc ? 1 : 0];
}

int las(vector <int> arr) {
    vector <vector <int>> dp(arr.size(), vector <int> (2));
    int maxLength = 1;

    for (int i = 0; i < arr.size(); i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
                maxLength = max(maxLength, dp[i][0]);
            } else if (arr[i] != arr[j]) {
                dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
                maxLength = max(maxLength, dp[i][1]);
            }
        }
    }

    return maxLength;
}

int longestAlter(vector <int> arr) {
    vector<vector <vector<int>>> dp(arr.size(), vector <vector <int>> (arr.size(), vector <int> (2, -1)));
    return max(las(arr, 0, -1, true, dp), las(arr, 0, -1, false, dp));
}

int main() {
    cout << longestAlter({1, 2, 3, 4}) << endl;
    cout << longestAlter({3, 2, 1, 4}) << endl;
    cout << longestAlter({1, 3, 2, 4}) << endl;
    return 0;
}