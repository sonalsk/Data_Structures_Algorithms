#include <bits/stdc++.h>
using namespace std;

// int coinChange(int amt, int curr) {
    
//     if (amt < 0 || curr >= 51) {
//         return 0;
//     }

//     if (amt == 0) {
//         return 1;
//     }

//     int inc = 0;
//     if ((curr * curr) <= amt) {
//         inc = coinChange(amt - (curr * curr), curr);
//     }

//     int exc = coinChange(amt, curr + 1);

//     return inc + exc;
// }

int coinChange(int amt, int curr, vector <vector <int>> dp) {
    
    if (amt < 0 || curr >= 51) {
        return 0;
    }

    if (amt == 0) {
        return 1;
    }

    if (dp[curr][amt] == -1) {
        int inc = 0;
        if ((curr * curr) <= amt) {
            inc = coinChange(amt - (curr * curr), curr, dp);
        }

        int exc = coinChange(amt, curr + 1, dp);
        dp[curr][amt] = inc + exc;
    }

    return dp[curr][amt];
}


int coinChang(int amt) {
    vector <vector <int>> dp(51, vector <int>(amt + 1, -1));
    return coinChange(amt, 1, dp);
}

int main() {
    cout << coinChang(4) << endl;
    return 0;
}