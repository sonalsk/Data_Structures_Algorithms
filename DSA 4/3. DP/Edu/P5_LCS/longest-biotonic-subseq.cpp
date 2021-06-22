#include <bits/stdc++.h>
using namespace std;

void print(vector <int> arr) {
    for (int i: arr) cout << i << " ";
    cout << endl;
}

int lis(vector <int> arr, int curr, int prev, int end) {
    if (curr == end) {
        return 0;
    }

    int inc = 0;
    if (prev == -1 || arr[curr] > arr[prev]) {
        inc = 1 + lis(arr, curr + 1, curr, end);
    }

    int exc = lis(arr, curr + 1, prev, end);
    
    return max(inc, exc);
}

int lds(vector <int> arr, int curr, int prev) {
    if (curr == arr.size()) {
        return 0;
    }

    int inc = 0;
    if (prev == -1 || arr[curr] < arr[prev]) {
        inc = 1 + lds(arr, curr + 1, curr);
    }

    int exc = lds(arr, curr + 1, prev);
    
    return max(inc, exc);
}

int longestBio(vector <int> arr) {
    int l = 0;
    for (int i = 0; i < arr.size(); i++) {
        int s = lis(arr, 0, -1, i + 1) + lds(arr, i, -1) - 1;

        l = max(l, s);
    }
    return l;
}

int main() {
    cout << longestBio({4, 2, 3, 6, 10, 1, 12}) << endl;
    cout << longestBio({4, 2, 5, 9, 7, 6, 10, 3, 1}) << endl;
    return 0;
}