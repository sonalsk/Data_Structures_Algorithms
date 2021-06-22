#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// Given an infinite supply of ‘n’ coin denominations and a total money amount, 
// we are asked to find the minimum number of coins needed to make up that amount.

int change(vector <int> deno, int total, int curr) {
    if (total == 0) {
        return 0;
    }
    if (total < 0 || curr >= deno.size()) {
        return INT_MAX;
    }

    int inc = INT_MAX;
    if (deno[curr] <= total) {
        int r = change(deno, total - deno[curr], curr);
        if (r != INT_MAX) {
          inc = r + 1;
        }
    }

    int exc = change(deno, total, curr + 1);
    return min(inc, exc);
}

int getChange(vector <int> denominations, int total) {
    return change(denominations, total, 0);
}

int main() {
    vector <int> denominations = {1, 2, 3};
    int total = 5;
    int change = getChange(denominations, total);
    cout << change << endl;
    return 0;
}