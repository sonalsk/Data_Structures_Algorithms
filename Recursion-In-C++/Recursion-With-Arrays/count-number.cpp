#include <bits/stdc++.h>

using namespace std;

int countNRec(vector <int> v, int n, int i) {
    int found = 0;
    if (i == v.size()) {
        return 0;
    }
    if (v[i] == n) {
        found++;
    }
    return found + countNRec(v, n, i + 1);
}

int countN(vector<int> v, int n) {
    return countNRec(v, n, 0);
}

int main() {
    vector <int> v = {2, 3, 4, 3, 7, 8, 3};
    int n = 3;
    cout << countN(v, n) << endl;
}