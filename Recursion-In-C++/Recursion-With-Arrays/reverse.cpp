#include <bits/stdc++.h>

using namespace std;

void reverseRec(vector <int> &v, int i, int j) {
    if (i > j) {
        return;
    }
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    reverseRec(v, i + 1, j - 1);
}

void reverse(vector <int> &v) {
    reverseRec(v, 0, v.size() - 1);
}

int main() {
    vector <int> v = {1, 2, 3, 4, 5, 6, 7};
    reverse(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}