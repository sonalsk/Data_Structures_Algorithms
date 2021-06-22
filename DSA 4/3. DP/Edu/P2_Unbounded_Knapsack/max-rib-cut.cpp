#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

// We are given a ribbon of length ‘n’ and a set of possible ribbon lengths. 
// We need to cut the ribbon into the maximum number of pieces that comply 
// with the above-mentioned possible lengths. 
// Write a method that will return the count of pieces.

int change(vector <int> deno, int total, int curr) {
    if (total == 0) {
        return 0;
    }
    if (total < 0 || curr >= deno.size()) {
        return INT_MIN;
    }

    int inc = INT_MIN;
    if (deno[curr] <= total) {
        int r = change(deno, total - deno[curr], curr);
        if (r != INT_MIN) {
          inc = r + 1;
        }
    }

    int exc = change(deno, total, curr + 1);
    return max(inc, exc);
}

int getChange(vector <int> lengths, int total) {
    return change(lengths, total, 0);
}

int main() {
    vector <int> lengths = {1, 2, 3};
    int total = 5;
    int change = getChange(lengths, total);
    cout << change << endl;
    return 0;
}