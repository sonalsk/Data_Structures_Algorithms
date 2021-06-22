#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// Given an infinite supply of ‘n’ coin denominations and a total money amount, 
// we are asked to find the total number of distinct ways to make up that amount.

int getAmt(vector <int> deno, int total, int start) {
    if (total < 0) {
        return 0;
    }

    if (total == 0) {
        return 1;
    }

    int s = 0;
    for (int i = start; i < deno.size(); i++) {
        s = s + getAmt(deno, total - deno[i], i);
    }

    return s;
}

int getAmt(vector <int> deno, int total, int start, vector <vector <int>> dp) {
    if (total < 0) {
        return 0;
    }

    if (total == 0) {
        return 1;
    }

    if (dp[start][total] == -1) {
        int s = 0;
        for (int i = start; i < deno.size(); i++) {
            s = s + getAmt(deno, total - deno[i], i, dp);
        }
        dp[start][total] = s;   
    }

    return dp[start][total];
}

int getAmt2(vector <int> deno, int total, int start) {
    if (total < 0 || start >= deno.size()) {
        return 0;
    }

    if (total == 0) {
        return 1;
    }

    int inc = 0;
    if (deno[start] <= total) {
        inc = getAmt2(deno, total - deno[start], start);
    }

    int exc = getAmt2(deno, total, start + 1);
    return inc + exc;    
}

int getAmt2(vector <int> deno, int total, int start, vector <vector <int>> dp) {
    if (total < 0 || start >= deno.size()) {
        return 0;
    }

    if (total == 0) {
        return 1;
    }

    if (dp[start][total] == -1) {
        int inc = 0;
        if (deno[start] <= total) {
            inc = getAmt2(deno, total - deno[start], start, dp);
        }

        int exc = getAmt2(deno, total, start + 1, dp);
        dp[start][total] = inc + exc;
    }
    
    return dp[start][total];    
}

int getChange(vector <int> denominations, int total) {
    vector <int> coins;
    // vector <vector <int>> dp(denominations.size(), vector <int>(total + 1, -1));
    return getAmt(denominations, total, 0);
}

int main() {
    vector <int> denominations = {1, 2, 3};
    int total = 5;
    int change = getChange(denominations, total);
    cout << change << endl;

    return 0;
}