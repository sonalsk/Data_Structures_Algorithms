#include <bits/stdc++.h>

using namespace std;

bool inSeq(vector <int> arr, int i) {
    if (i == 0) {
        return true;
    }
    return ((arr[i] - arr[i - 1]) == 1) && inSeq(arr, i - 1);
}

bool inSeq(vector <int> arr) {
    if (arr.size() == 0) {
        return false;
    }
    return inSeq(arr, arr.size() - 1);
}

int main() {
    vector <int> arr = {2, 3, 4, 5};

    if (inSeq(arr)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}