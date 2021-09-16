#include <bits/stdc++.h>

using namespace std;

void replaceRec(vector <int> &v, int i) {
    if (i == v.size()) {
        return;
    }
    if (v[i] < 0) {
        v[i] = 0;
    }
    replaceRec(v, i + 1);
}

void replaceWith0(vector <int> &v) {
    replaceRec(v, 0);
}

int main() {
    vector <int> v = {2, -3, 4, -1, -7, 8, 3};
    replaceWith0(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
