#include <bits/stdc++.h>

using namespace std;

int firstOccRec(vector<int> v, int n, int i) {
    if (i == v.size()) {
        return -1;
    }
    if (v[i] == n) {
        return i;
    }
    return firstOccRec(v, n, i + 1);
}

int firstOcc(vector <int> v, int n) {
    return firstOccRec(v, n, 0);
}

int main() {
    vector <int> v = {2, 4, 1, 7, 8, 3};
    int n = 3;
    cout << firstOcc(v, n) << endl;
    return 0;
}