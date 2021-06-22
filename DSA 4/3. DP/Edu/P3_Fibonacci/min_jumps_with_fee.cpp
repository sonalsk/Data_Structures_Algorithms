#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// Given a staircase with ‘n’ steps and an array of ‘n’ numbers 
// representing the fee that you have to pay if you take the step. 
// Implement a method to calculate the minimum fee 
// required to reach the top of the staircase (beyond the top-most step).
// At every step, you have an option to take either 1 step, 2 steps, or 3 steps. 
// You should assume that you are standing at the first step.


int minJumps(vector <int> fee, int curr) {
    if (curr > fee.size() - 1) {
        return 0;
    }

    int one = minJumps(fee, curr + 1);
    int two = minJumps(fee, curr + 2);
    int three = minJumps(fee, curr + 3);

    return fee[curr] + min(one, min(two, three));
}

int minJumps(vector <int> fee, int curr, vector <int> dp) {
    if (curr > fee.size() - 1) {
        return 0;
    }

    if (dp[curr] != 0) {
        return dp[curr];
    }
    
    int one = minJumps(fee, curr + 1);
    int two = minJumps(fee, curr + 2);
    int three = minJumps(fee, curr + 3);

    dp[curr] = fee[curr] + min(one, min(two, three));
    return dp[curr];
}

int minJumps(vector <int> fee) {
    vector <int> dp(fee.size() + 1, 0);
    dp[0] = 0;
    dp[1] = fee[0];
    dp[2] = fee[0]; 

    for (int i = 3; i <= fee.size(); i++) {
        dp[i] = min(fee[i - 1] + dp[i - 1], min(fee[i - 2] + dp[i - 2], fee[i - 3] + dp[i - 3]));
    }

    return dp[fee.size()];
}

int getMinJump(vector <int> fee) {
    return minJumps(fee, 0);
}

int main() {
    vector <int> fee = {1, 2, 5, 2, 1, 2};
    int minJumps = getMinJump(fee);
    cout << minJumps << endl;
    return 0;
}