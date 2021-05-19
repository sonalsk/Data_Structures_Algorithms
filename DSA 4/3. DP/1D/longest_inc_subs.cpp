#include <bits/stdc++.h>

using namespace std;

void print(vector <int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void allSubSeq(vector <int> &arr, int i, vector <int> subseq) {
    if (i == arr.size()) {
        print(subseq);
        return;
    }
    subseq.push_back(arr[i]);
    allSubSeq(arr, i + 1, subseq);
    subseq.pop_back();
    allSubSeq(arr, i + 1, subseq);
}

void allIncSubSeq(vector <int> &arr, int i, vector <int> subseq) {
    if (i == arr.size()) {
        print(subseq);
        return;
    }
    if (subseq.size() == 0 || (subseq.size() > 0 && arr[i] > subseq.back())) {
        subseq.push_back(arr[i]);
        allIncSubSeq(arr, i + 1, subseq);
        subseq.pop_back();
    }
    allIncSubSeq(arr, i + 1, subseq);
}

void longIncSubSeq(vector <int> &arr, int i, vector <int> subseq, int &m) {
    if (i == arr.size()) {
        if (subseq.size() > m) {
            m = subseq.size();
        }
        return;
    }
    if (subseq.size() == 0 || (subseq.size() > 0 && arr[i] > subseq.back())) {
        subseq.push_back(arr[i]);
        longIncSubSeq(arr, i + 1, subseq, m);
        subseq.pop_back();
    }
    longIncSubSeq(arr, i + 1, subseq, m);
}

void lenIncSubSeqCount(vector <int> &arr, int i, int p, int l) {
    if (i == arr.size()) {
        cout << l << " ";
        return;
    }
    if (l == 0 || (l > 0 && arr[i] > arr[p])) {
        l = l + 1;
        lenIncSubSeqCount(arr, i + 1, i, l);
        l = l - 1;
    }
    lenIncSubSeqCount(arr, i + 1, p, l);
}

// recursion
int longIncSubSeqCount(vector <int> &arr, int i) {
    if (i == 0) {
        return 0;
    }

    int m = 1;
    for (int j = 0; j < i; j++) {
        int lis = longIncSubSeqCount(arr, j);

        if (arr[i] > arr[j]) {
            lis += 1;
        }

        m = max(m, lis);
    }

    return m;
}

// top down
int longIncSubSeqTD(vector <int> &arr, int i, vector <int> dp) {
    if (i == 0) {
        return 0;
    }

    if (dp[i]) {
        return dp[i];
    }

    int m = 1;
    for (int j = 0; j < i; j++) {
        int lis = longIncSubSeqTD(arr, j, dp);

        if (arr[i] > arr[j]) {
            lis += 1;
        }

        m = max(m, lis);
    }
    dp[i] = m;
    return dp[i];
}

// bottom Up
int bottomUp(vector <int> &arr) {
    vector <int> dp(arr.size());
    dp[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            int lis = dp[j];
            if (arr[i] > arr[j]) {
                lis += 1;
            }
            dp[i] = max(dp[i], lis);
        }
    }
    return dp[arr.size() - 1];
}

void longestSubSeq(vector <int> &arr) {
    cout << longIncSubSeqCount(arr, 0);
    vector <int> dp(arr.size(), 0);
    cout << longIncSubSeqTD(arr, 0, dp);
    cout << endl;
}


int main() {
    vector <int> arr = {5,2,3,6,8};
    longestSubSeq(arr);
    return 0;
}